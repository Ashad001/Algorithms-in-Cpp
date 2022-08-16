import os
import random
# Program To Randomly Play Videos
p = "" # Give a path to a folder that has some random folders and each forlder contain some videos!!!
os.chdir(p)  # change directory

folder_name = random.choice(os.listdir(p))   # choose a random folder
folder_path = str(os.path.realpath(folder_name))     # copy its path
os.chdir(folder_path)         # change its directory to that path
file_name = random.choice(os.listdir(folder_path))      # choose a file from that directory

# os.system('start ' + file_name)    # play that file but this does not play
