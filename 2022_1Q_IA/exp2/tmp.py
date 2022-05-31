import subprocess

print("in python file")
subprocess.call(["g++", "floyd.cpp"])
subprocess.call("./a.out")
print("task is done")
