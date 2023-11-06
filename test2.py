import numpy as np
from scipy.spatial import Delaunay
import matplotlib.pyplot as plt

# Generate random points as an example
np.random.seed(0)
points = np.random.rand(100, 2)

# Compute the Delaunay triangulation
tri = Delaunay(points)

# Plot the Delaunay triangulationp
plt.triplot(points[:,0], points[:,1], tri.simplices)
plt.plot(points[:,0], points[:,1], 'o')
plt.show()
