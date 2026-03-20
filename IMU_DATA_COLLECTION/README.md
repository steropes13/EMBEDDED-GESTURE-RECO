# IMU Data Collection for training the Gesture Recognition Model 
This project is used to collect data from the IMU sensor of the ESP32 board, which is used to train the Gesture Recognition Model. The data is collected in a CSV format and can be used for training the model.

# Compiling the project (using VSCode and PlatformIO)
1. Install VSCode on you PC;
2. Install PlatformIO from the extension menu on VSCode;
3. Clone the repository on your local machine;
4. Open it using VSCode;
5. After PlatformIO loads, select the Environment for you own board from the down bar;
6. Click on Upload on the down bar;
7. Open the Console.
> NOTE: PlatformIO needs access to USB ports, maybe it's needed to update udev rules under linux or installing some driver for different OSes 

# Compiling the project (using PlatformIO CLI)
1. Install PlatformIO CLI on your PC, following the instructions on the official (website)[https://docs.platformio.org/en/latest/core/installation/methods/index.html];
2. Allow PlatformIO to access USB ports, maybe it's needed to update udev rules under linux or installing some driver for different OSes;
3. Be sure to have acces to PlatformIO Core CLI binaries, see (here)[https://docs.platformio.org/en/latest/core/installation/shell-commands.html] for more details;
4. Clone the repository on your local machine;
5. Open a terminal and navigate to the project folder;
6. Run the command `pio run -e <environment_name> -t upload` to compile and upload the code to your board, replacing `<environment_name>` with the name of the environment you want to use (`nano33ble_SenseRev2` or `nano33ble_Sense`);
7. Open the Console.