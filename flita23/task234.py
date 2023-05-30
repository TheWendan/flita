import graphviz
import networkx as nx

def connection(adjmatrix):
    num_vertices = len(adjmatrix)
    max_edges = (num_vertices - 1) * (num_vertices - 2) // 2
    num_edges = sum(sum(row) for row in adjmatrix) // 2
    return num_edges >= max_edges

def create_graph(adj_matrix):
    # Создаем новый ненаправленный граф
    dot = graphviz.Graph(strict=False)
    # Добавляем узлы в граф
    for i in range(len(adj_matrix)):
        dot.node(str(i))
    # Добавляем ребра в граф
    for i in range(len(adj_matrix)):
        for j in range(i, len(adj_matrix[i])):
            if adj_matrix[i][j] != 0:
                dot.edge(str(i), str(j), label=str(adj_matrix[i][j]))
    # Возвращаем граф
    return dot

counter1 = 0
# открыть файл на чтение
with open("matrix.txt", "r") as file:
    # прочитать строки файла и разбить их по символу пробела
    lines = file.readlines()
    matrix = []
    for line in lines:
        row = line.strip().split(" ")
        # преобразовать элементы строки в целочисленный тип и добавить в матрицу
        matrix.append([int(x) for x in row])

adjmatrix = [[0 for i in range(len(matrix))] for j in range(len(matrix))] # создание матрицы смежности
for j in range(len(matrix[0])): # рёбра
    for i in range(len(matrix)): # строки
        if matrix[i][j] == 1:
            counter1 += 1
            if counter1 == 1:
                buff = i
        if counter1 == 2:
            adjmatrix[buff][i] += 1
            adjmatrix[i][buff] += 1
            counter1 = 0
    if counter1 == 1:
        adjmatrix[buff][buff] += 1 # петли
        counter1 = 0
for row in adjmatrix:
    print(row)
print(len(matrix[0])) # вершины
print(len(matrix)) # рёбра

if connection(adjmatrix):
    print("Граф связан")
else:
    print("Граф не связан")
graph = create_graph(adjmatrix)
graph.view()















    