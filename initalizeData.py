import os
from sys import argv #[0] is directory of terminal... or file... one of em.

directory = ""
gitDirectory = ""
gitRemoteName = ""
projectDirectory = ""

if len(argv) != 0:
    pathways = argv[1].split("525292925252929252529292") #for some reason argv wont split the pathways when i put a space, so now we're here
    pathways = [pathway.replace("\"", "") for pathway in pathways]
    directory = pathways[0]
    gitDirectory = pathways[1]
    gitRemoteName = pathways[2]
    projectDirectory = pathways[3]

if not os.path.exists(directory):
    command = "mkdir " + directory
    os.system(command)

if not os.path.exists(directory + "\\" + gitRemoteName):
    #command = "git clone \"" + gitDirectory + "\" \"" + gitRemoteName + "\""
    command = "git clone -q \"" + gitDirectory + "\" \"" + directory + "\\" + gitRemoteName + "\""
    os.system(command)
else:
    command = projectDirectory + "\\" + "pull.bat" + " \"" + directory + "\\" + gitRemoteName + "\""
    os.system(command)

#print(directory + "\\" + gitRemoteName + "\\" + "data.txt")
'''
if not os.path.exists(directory + "\\" + gitRemoteName + "\\" + "data.txt"):
    blah =  directory + "\\" + gitRemoteName
    command = "echo > " + blah + "\\" + "data.txt"
    #print(command)
    os.system(command)
    command = "git add " + blah + "\\" + "data.txt"
    #print(command)
    os.system(command)                   #os.system breaks if you just shove the text from command directly in, dunno why
    command = "git commit -m \"Action\" " + blah
    #print(command)
    os.system(command)
    command = "git push " + blah
    #print(command)
    os.system(command)
'''