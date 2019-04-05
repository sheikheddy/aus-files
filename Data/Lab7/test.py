import numpy as np
import matplotlib.pyplot as plt

def graph_results(file_name):
    data = np.genfromtxt(file_name, delimiter=',', names=['size','time'])
    plt.plot(data['size'], data['time'])
    plt.xlabel('Size of input N')
    plt.ylabel('Time taken t')
    return 