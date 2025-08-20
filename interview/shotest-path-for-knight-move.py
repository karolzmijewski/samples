# PROBLEM
# Find shortest path for the knight move from start to end

from collections import deque

def create_graph():
    chess_playground = { }
    x = ["a", "b", "c", "d", "e", "f", "g", "h"]
    y = ["1", "2", "3", "4", "5", "6", "7", "8"]
    for i in range(0, len(x)):
        for j in range(0, len(y)):
            curr_pos = x[i] + y[j]
            print(f"curr_pos = {curr_pos}")
            if not curr_pos in chess_playground:
                chess_playground[curr_pos] = []
            try:
                chess_playground[curr_pos].append(x[i + 2] + y[j + 1])
            except IndexError as e:
                print(f"LEFT: {e}")
            try:
                if i - 2 >= 0:
                    chess_playground[curr_pos].append(x[i - 2] + y[j + 1])
            except IndexError as e:
                print(f"LEFT: {e}")
            try:
                if j - 1 >= 0:
                    chess_playground[curr_pos].append(x[i + 2] + y[j - 1])
            except IndexError as e:
                print(f"LEFT: {e}")
            try:
                if i - 2 >= 0 and j - 1 >= 0:
                    chess_playground[curr_pos].append(x[i - 2] + y[j - 1])
            except IndexError as e:
                print(f"LEFT: {e}")
            try:
                chess_playground[curr_pos].append(x[i + 1] + y[j + 2])
            except IndexError as e:
                print(f"LEFT: {e}")
            try:
                if i - 1 >= 0:
                    chess_playground[curr_pos].append(x[i - 1] + y[j + 2])
            except IndexError as e:
                print(f"LEFT: {e}")
            try:
                if j - 2 >= 0:
                    chess_playground[curr_pos].append(x[i + 1] + y[j - 2])
            except IndexError as e:
                print(f"LEFT: {e}")
            try:
                if i - 1 >= 0 and j - 2 >= 0:
                    chess_playground[curr_pos].append(x[i - 1] + y[j - 2])
            except IndexError as e:
                print(f"LEFT: {e}")
    return chess_playground

def get_shortest_chess_knight_path(start: str, end: str) -> list[str]:
    visited = []
    chess_playground = create_graph()

    def bfs(queue):
        if not queue:
            return []
        path = queue.pop(0)
        node = path[-1]
        #print(f"visiting: {node}")
        if node == end:
            return path
        visited.append(node)
        for nn in chess_playground[node]:
            if nn not in visited:
                queue.append(path + [nn])
        return bfs(queue)

    # print(f"graph:")
    # for k, v in chess_playground.items():
    #     print(f"{k}: {v}")
    
    return bfs([[start]])

get_shortest_chess_knight_path("a1", "b3")