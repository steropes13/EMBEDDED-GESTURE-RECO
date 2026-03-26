/*
  IMU Capture
  This example uses the on-board IMU to start reading acceleration and gyroscope
  data from on-board IMU and prints it to the Serial Monitor for one second
  when the significant motion is detected.
  You can also use the Serial Plotter to graph the data.
  The circuit:
  - Arduino Nano 33 BLE or Arduino Nano 33 BLE Sense board.
  Created by Don Coleman, Sandeep Mistry
  Modified by Dominic Pajak, Sandeep Mistry
  This example code is in the public domain.
*/

#include <Arduino.h>

#ifdef NANO33BLE_SENSE_REV2
  #include <Arduino_BMI270_BMM150.h>
#elif defined(NANO33BLE_SENSE)
  #include <Arduino_LSM9DS1.h>
#endif

typedef struct {
  uint64_t millis;
  float ax;
  float ay;
  float az;
  float gx;
  float gy;
  float gz;
} IMUData;

const float accelerationThreshold = 2.5; // threshold of significant in G's
const int numSamples = 128;
IMUData dataSamples[numSamples];

int samplesRead = numSamples;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  // print the header
  Serial.println("millis,aX,aY,aZ,gX,gY,gZ");
}

/*!
  @brief Prints the data in CSV format

  @param data the data to print
  @param sampleLen the number of samples in the data, defaults to `numSamples`

  @returns void
 */
void printData(IMUData* data, uint32_t sampleLen = numSamples) {
  for(int i = 0; i < sampleLen; i++){
    Serial.print(data[i].millis);
    Serial.print(',');
    Serial.print(data[i].ax, 3);
    Serial.print(',');
    Serial.print(data[i].ay, 3);
    Serial.print(',');
    Serial.print(data[i].az, 3);
    Serial.print(',');
    Serial.print(data[i].gx, 3);
    Serial.print(',');
    Serial.print(data[i].gy, 3);
    Serial.print(',');
    Serial.print(data[i].gz, 3);
    Serial.println();

  }
  Serial.println();
}

void loop() {
  float aX, aY, aZ;

  // wait for significant motion
  while (samplesRead == numSamples) {
    if (IMU.accelerationAvailable()) {
      // read the acceleration data
      IMU.readAcceleration(aX, aY, aZ);

      // sum up the absolutes
      float aSum = fabs(aX) + fabs(aY) + fabs(aZ);

      // check if it's above the threshold
      if (aSum >= accelerationThreshold) {
        // reset the sample read count
        samplesRead = 0;
        break;
      }
      
    }
  }

  // check if the all the required samples have been read since
  // the last time the significant motion was detected
  while (samplesRead < numSamples) {
    // check if both new acceleration and gyroscope data is
    // available
    if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
      // read the acceleration and gyroscope data
      IMU.readAcceleration(dataSamples[samplesRead].ax, dataSamples[samplesRead].ay, dataSamples[samplesRead].az);
      IMU.readGyroscope(dataSamples[samplesRead].gx, dataSamples[samplesRead].gy, dataSamples[samplesRead].gz);
      dataSamples[samplesRead].millis = millis(); 
      samplesRead++;
    }
  }

  printData(dataSamples);
}
