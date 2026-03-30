# How to use the *jupyter-notebook* locally   

*Version of python* : 3.11 in order to use Tensorflow which is deprecated for versions > python3.11 
If you want to use the notebooks it is recommended to use a virtual environment, here is a list of instructions 

## install of the python3.11
 some examples depending on your package manager. 
MAC OS X 
```bash   
brew install python@3.11 
```

GNU/LINUX (Ubuntu) : 
```bash   
sudo apt instal python3.11 
```
## Creation of the environment in command-line 

```bash   
python3.11 -m venv .venv 
```

## Activation of the environment 
```bash   
source .venv/bin/activate
```
Normally, you will see the name of your environment shown before your prompt like bellow : 
```bash   
(.venv) streopes13@steropes13 $ ls -al 
```

## installation of jupyter notebook 
```bash   
pip3 install jupyter-notebook 
```
other version : 
```bash   
python3 -m pip install jupyter-notebook
```
by replacing <jupyter-notebook> you can install libraries needed (_pandas, tensorflow, keras.._) 

## _(If needed)_ Deactivate the environment 
```bash   
deactivate
```

## _(optional)_  Verification of the environment 
Execute this command 
```bash   
which python 
which pip 
```
if it shows the *path of the venv* it works correctly 


## _(optional)_  Verification of the environment in jupyter-notebook
in a cell specified of python of notebook file (_ipynb_)  you can verify if it uses also the same environment as you have created. 
```python   
import sys 
print(sys.executable) 
```
if after executing this cell it shows you the path of your virtual environment, it works ! 

# Link of the google Collab [here](https://colab.research.google.com/drive/1zVgsqpySxEAGOxTOStpjsPD_wjLUeIkG?usp=sharing)

# Instructions for the Google Colab 
You have to import the diferent `.csv` files of this repository (in the `data-gestures`repository in the notebook at the same leval as `sample_data`).

# Running the PlatformIO projects
## Dependencies
To run the PlatformIO projects, you will need to have the PlatformIO CLI installed on your system. You can install it using following the instructions on the [PlatformIO website](https://docs.platformio.org/en/latest/core/installation/methods/index.html). A more detailed instruction is available in the [`README.md`](./IMU_GESTURE_RECO/README.md#compiling-the-project) file of the `IMU_GESTURE_RECO` directory.

## Compiling the code and uploading the firmware
Using the PlatformIO CLI, you can compile the project using:
```bash
pio run -e <environment_name> -t upload -d <project_directory>
```
> Make sure to replace `<environment_name>` with the name of the environment you want to use (`nano33ble_SenseRev2` or `nano33ble_Sense`).

> Make sure to replace `<project_directory>` with the path to the project you want to compile (`./IMU_GESTURE_RECO` or `./IMU_GESTURE_RECO`).

## Monitoring the serial output
After uploading the firmware, you can monitor the serial output using:
```bash
pio device -t monitor -d <project_directory>
```

## Other information
If you want to compile the project testing all the environments, you can use the command:
```bash
pio run -d <project_directory>
```

# Collecting data with the `IMU_DATA_COLLECTION` project and the `collect_data.py` script
## Dipendencies
To collect data using the `collect_data.py` script, you will need to have Python installed on your system, along with the `pyserial` library. You can install `pyserial` using pip:
```bash
pip install pyserial
```

## Running the data collection script
To run the data collection first of all upload the firmware of the `IMU_DATA_COLLECTION` as described in the previous section. Then, you can run the `collect_data.py` script using:

```bash
python collect_data.py <file_name> 
```
After running this command, the script will ask a number to the corrisponding port you want from the list. 

> Make sure to replace `<file_name>` with the name of the file you want to save the collected data to (e.g., `data-gestures/circle-1.csv`).