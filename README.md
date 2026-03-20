# list of instructions [TODO] 
- up-down, rest and shake work but not circle (only with a specific configuration of the hand) -> more datas for circle
- explications of the PSD mean and PSD Max in .ino file 
- more Neurons for Relu ?
- Add explications about relu.
- Complete the missing tasks ? 
- Clarify/clean the ipynb (graph of loss, optimizer ?) 
- Very the problem of 141 samples.
- Real matrix or ASCII is sufficient ? 


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
You have to import the diferent `.csv` files of this repository (in the `datas-gestures`repository in the notebook at the same leval as `sample_data` 

# instructions for the gesture classification file : 
To use this file in the format `.ino` (in the directory `IMU_GESTURE_CLASSIFICATION/`) it is necessary to import the model (named `model.h`) in this directory, that you can get by the google colab (or the `.ipynb` file locally on you computer). 
If you want to test the "circle" gesture you will have to rotate your wrist at the same time you are drawing the cirle, same as on a piece of paper) 

# Instructions for the IMU acquisition 
If you want to create your own datas you will have to use the `.ino` file located in the repository `IMU/` and name them respectively : 
```
 - circle-1.csv
 - rest-1.csv
 - up-down-1.csv
 - shake-1.csv
```

# Running the PlatformIO projects
## Dependencies
To run the PlatformIO projects, you will need to have the PlatformIO CLI installed on your system. You can install it using following the instructions on the [PlatformIO website](https://docs.platformio.org/en/latest/core/installation/methods/index.html). A more detailed instruction is available in the [`README.md`](./IMU_DATA_COLLECTION/README.md) file of the `IMU_DATA_COLLECTION` directory.

## Compiling the code and uploading the firmware
Using the PlatformIO CLI, you can compile the project using:
```bash
pio run -e <environment_name> -t upload -d <project_directory>
```
> Make sure to replace `<environment_name>` with the name of the environment you want to use (`nano33ble_SenseRev2` or `nano33ble_Sense`).

> Make sure to replace `<project_directory>` with the path to the project you want to compile (the `./IMU_DATA_COLLECTION` is the only available for this moment).

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

