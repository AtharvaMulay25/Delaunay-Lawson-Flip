import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial import Delaunay

# Function to compute the scan-line triangulation from Delaunay triangulation
def scan_triangulation_from_delaunay(tri):
    simplices = tri.simplices
    triangles = []

    for simplex in simplices:
        a, b, c = sorted(simplex)
        triangles.append((a, b))
        triangles.append((b, c))
        triangles.append((c, a))

    return triangles

# Function to plot the triangulation
def plot_triangulation(triangles, points):
    plt.figure()
    for edge in triangles:
        a, b = edge
        plt.plot(points[[a, b], 0], points[[a, b], 1], 'b-')

    plt.scatter(*zip(*points), c='r', marker='o')
    plt.gca().set_aspect('equal', adjustable='box')
    plt.title("Scan-Line Triangulation")
    plt.show()

if __name__ == "__main__":
    # Generate random points
    np.random.seed(0)
    num_points = 20
    points = np.random.rand(num_points, 2)

    # Compute the Delaunay triangulation
    tri = Delaunay(points)

    # Generate the scan-line triangulation from the Delaunay triangulation
    scan_triangles = scan_triangulation_from_delaunay(tri)

    plot_triangulation(scan_triangles, points)
