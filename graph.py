import os
import matplotlib.pyplot as plt
import numpy as np
name = ['Time_FFT_MULT.txt','Time_NAIVE_MULT.txt']

with open(name[0],'r') as file:
    lines = file.readlines()

# Extracting data from each line
x1 = []
y1= []
for line in lines:
    # Split each line into two parts (assuming space-separated values)
    parts = line.strip().split()
    # Convert strings to integers
    x1.append(int(parts[0]))
    y1.append(int(parts[1]))


with open(name[1],'r') as file:
    lines = file.readlines()

# Extracting data from each line
x = []
y = []
for line in lines:
    # Split each line into two parts (assuming space-separated values)
    parts = line.strip().split()
    # Convert strings to integers
    x.append(int(parts[0]))
    y.append(int(parts[1]))

output_directory = 'Graph of time'
if not os.path.exists(output_directory):
    os.makedirs(output_directory)


plt.plot(x, (y), linestyle='-', color='b', label=name[1])
plt.plot(x1, (y1), linestyle='-', color='r', label=name[0])
plt.title('Graph of time/size')
plt.xlabel('Size of polynomials')
plt.ylabel('Time in Seconds')

plt.legend()
plt.savefig(os.path.join(output_directory, 'size.png'))

plt.show()

