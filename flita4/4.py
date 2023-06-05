import networkx as nx
import random
import time
import matplotlib.pyplot as plt

vertex_counts = [500,2000,3000,5000]  # Cписок количества вершин
time_records = []

#Cоздание списка ребер для графа без петель и кратных ребер, вследствие чего временная сложность удаления 1 вершины будет квадратичной
for vertex_count in vertex_counts:
    edge_list = [(i, j) for i in range(vertex_count) for j in range(i + 1, vertex_count)]
    random.shuffle(edge_list)

    G = nx.Graph()  # Создаем граф
    G.add_edges_from(edge_list)

    while True:
        print("Введите вершину для удаления из", vertex_count)
        node_to_remove = int(input())

        if node_to_remove in G:
            break
        else:
            print("Такой вершины не существует")

    start_time = time.time()
    G.remove_node(node_to_remove) # Удаляем выбранное вершину и замеряем время
    end_time = time.time()
    node_removal_time = end_time - start_time

    start_time = time.time()  
    sorted_vertices = sorted(G.nodes(), key=lambda x: G.degree(x), reverse=False) # сортируем по возрастанию
    sorting_time = end_time - start_time
    total_time = sorting_time + node_removal_time
    time_records.append(total_time)  # Добавляем общее время выполнения в список

plt.plot(vertex_counts, time_records) # Построим график времени выполнения в зависимости от количества вершин
plt.xlabel('Кол-во вершин')
plt.ylabel('Время в секундах')
plt.title('Зависимость времени от количества')
plt.show()