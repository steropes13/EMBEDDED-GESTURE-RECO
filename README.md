# list of instructions [TODO]


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
python3.11 -m venv venv_name 
```

## Activation of the environment 
```bash   
source venv_name/bin/activate
```
Normally, you will see the name of your environment shown before your prompt like bellow : 
```bash   
(venv_name) streopes13@steropes13 $ ls -al 
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
