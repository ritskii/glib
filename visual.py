import matplotlib.pyplot as plt

x, y = [], []
with open('points.txt', 'r') as f:
    for line in f:
        xi, yi = map(float, line.split())
        x.append(xi)
        y.append(yi)

plt.scatter(x, y, c='blue', marker='o')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('2D Visualization of Points')
plt.grid(True)
plt.show()
