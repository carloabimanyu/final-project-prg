import matplotlib.pyplot as plt

file_t = open('data_t.txt', 'r')
file_x = open('data_x.txt', 'r')
data_t = [float(t) for t in file_t]
data_x = [float(x) for x in file_x]
file_t.close()
file_x.close()

plt.plot(data_t, data_x)
plt.title('Plot x(t) pada osilasi teredam')
plt.xlabel('Waktu (t)')
plt.ylabel('Simpangan (x)')
plt.show()