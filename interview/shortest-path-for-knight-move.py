# PROBLEM
# Find shortest path for the knight move from start to end

def create_graph():
    moves_graph = { }
    X = ["a", "b", "c", "d", "e", "f", "g", "h"]
    Y = ["1", "2", "3", "4", "5", "6", "7", "8"]
    MOVES = [ (2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2) ]
    X_SIZE = len(X)
    Y_SIZE = len(Y)

    for i in range(0, X_SIZE):
        for j in range(0, Y_SIZE):
            curr_pos = X[i] + Y[j]
            if not curr_pos in moves_graph:
                moves_graph[curr_pos] = []
            for move in MOVES:
                curr_move_x = i + move[0]
                curr_move_y = j + move[1]
                if 0 <= curr_move_x and curr_move_x <= (X_SIZE - 1) and 0 <= curr_move_y and curr_move_y <= (Y_SIZE - 1):
                    moves_graph[curr_pos].append(X[curr_move_x] + Y[curr_move_y])
    return moves_graph

def get_shortest_chess_knight_path(start: str, end: str) -> list[str]:
    visited = []
    moves_graph = create_graph()

    def bfs(queue):
        if not queue:
            return []
        path = queue.pop(0)
        node = path[-1]
        if node == end:
            return path
        visited.append(node)
        for nn in moves_graph[node]:
            if nn not in visited:
                queue.append(path + [nn])
        return bfs(queue)

    # print(f"graph:")
    # for k, v in moves_graph.items():
    #     print(f"{k}: {v}")
    
    return bfs([[start]])

get_shortest_chess_knight_path("a1", "b3")