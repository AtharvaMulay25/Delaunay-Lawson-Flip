import matplotlib.pyplot as plt

# Function to parse the input file
def parse_file(filename):
    triangles = []
    with open(filename, 'r') as file:
        n = int(file.readline())
        for _ in range(n):
            triangle_edges = []
            for _ in range(3):
                edge = tuple(map(float, file.readline().split()))
                print(edge)
                triangle_edges.append(edge)
            triangles.append(triangle_edges)
            file.readline()
    return triangles

# Function to draw the triangulation
def draw_and_display(triangles, title, subplot):
    plt.subplot(subplot)
    for triangle_edges in triangles:
        for edge in triangle_edges:
            x1, y1, x2, y2 = edge
            plt.plot([x1, x2], [y1, y2], color='b')
    plt.gca().set_aspect('equal', adjustable='box')
    plt.title(title)    

if __name__ == "__main__":
    input_file = "./input/input.txt"  
    output_file = "./output/output.txt" 
    
    given_triangulation = parse_file(input_file)
    # delaunay_triangulation = parse_file(output_file)
    
    plt.figure(figsize=(10, 5))  # Create a single figure with a specified size
    
    draw_and_display(given_triangulation, "Given_Triangulation", 121)  # First subplot
    # draw_and_display(delaunay_triangulation, "Delaunay_Triangulation", 122)  # Second subplot
    
    plt.tight_layout()  # Ensure proper spacing between subplots
    plt.show()




