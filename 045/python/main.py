class Graph:

    def __init__(self, vs, es):
        self.vs = vs
        self.es = es


def f1(graph, src):
    """Dijkstra"""
    vs = graph.vs
    es = graph.es

    ds = {}
    sees = set()
    pqs = set()

    for v in vs:
        ds[v] = None
    ds[src] = 0
    pqs.add(src)

    while pqs:
        v0, d0 = None, None
        for v in pqs:
            if ds[v] is not None and (d0 is None or d0 > ds[v]):
                v0, d0 = v, ds[v]
        pqs.remove(v0)
        sees.add(v0)

        e = es[v0]
        for v, d1 in e.items():
            if v not in sees:
                d = d0 + d1
                if ds[v] is None or d < ds[v]:
                    ds[v] = d
                    pqs.add(v)

    return ds


def f2(graph, src, dst):
    """A*"""
    vs = graph.vs
    es = graph.es

    ds = {}
    sees = set()
    pqs = set()

    for v in vs:
        ds[v] = None
    ds[src] = 0
    pqs.add(src)

    while pqs:
        v0, d0 = None, None
        for v in pqs:
            if ds[v] is not None and (d0 is None or d0 > ds[v]):
                v0, d0 = v, ds[v]

        if v0 == dst:
            return d0

        pqs.remove(v0)
        sees.add(v0)

        e = es[v0]
        for v, d1 in e.items():
            if v not in sees:
                d = d0 + d1
                if ds[v] is None or d < ds[v]:
                    ds[v] = d
                    pqs.add(v)

    return None


def jump1(nums):
    if len(nums) == 1:
        return 0

    num = nums[0]
    if num >= len(nums) - 1:
        return 1

    res = []
    for n in range(num - 1, -1, -1):
        if n + 1 < len(nums):
            r = jump1(nums[n + 1:])
            if r is not None:
                if r == 1:
                    return 2
                res.append(r)
    if not res:
        return None
    return 1 + min(res)


def cache_jump(jump):
    cache = {}
    def jump0(nums):
        n = len(nums)
        if n in cache:
            return cache[n]
        res = jump(nums)
        cache[n] = res
        return res
    return jump0


def jump2(nums):
    @cache_jump
    def jump0(nums):
        if len(nums) == 1:
            return 0

        num = nums[0]
        if num >= len(nums) - 1:
            return 1

        res = []
        for n in range(num - 1, -1, -1):
            if n + 1 < len(nums):
                r = jump0(nums[n + 1:])
                if r is not None:
                    if r == 1:
                        return 2
                    res.append(r)
        if not res:
            return None
        return 1 + min(res)
    return jump0(nums)


def generate_graph(nums):
    vs = list(range(len(nums)))
    es = {}
    for v in vs:
        num = nums[v]
        es[v] = {}
        for i in range(num):
            if v + i + 1 < len(nums):
                es[v][v + i + 1] = 1
    return Graph(vs, es)


def jump3(nums):
    graph = generate_graph(nums)
    return f2(graph, 0, len(nums) - 1)


def jump4(nums):
    if len(nums) == 1:
        return 0

    k = 0
    m1, m2 = -1, 0
    while True:
        m = m2
        k += 1
        for i in range(m1 + 1, m2 + 1):
            m = max(m, i + nums[i])
            if m >= len(nums) - 1:
                return k
        m1, m2 = m2, m


def jump5(nums):
    if len(nums) == 1:
        return 0

    k = 0
    m1, m2 = 0, 0
    for i in range(len(nums)):
        m2 = max(m2, i + nums[i])
        if i == m1:
            k += 1
            m1 = m2
    return k


if __name__ == "__main__":
    vs = ["A", "B", "C", "D", "E", "F", "G"]
    es = {
        "A": {"B": 12, "F": 16, "G": 14},
        "B": {"A": 12, "C": 10, "F": 7},
        "C": {"B": 10, "D": 3, "E": 5, "F": 6},
        "D": {"C": 3, "E": 4},
        "E": {"C": 5, "D": 4, "F": 2, "G": 8},
        "F": {"A": 16, "B": 7, "C": 6, "E": 2, "G": 9},
        "G": {"A": 14, "E": 8, "F": 9},
    }
    graph = Graph(vs, es)
    print(f1(graph, "D"))
    print({v: f2(graph, "D", v) for v in ["A", "B", "C", "D", "E", "F", "G"]})

    print("===== jump1 =====")
    print(jump1([2, 3, 1, 1, 4]), end=" ")
    print(jump1([2, 3, 0, 1, 4]), end=" ")
    print(jump1([2, 1]), end=" ")
    print(jump1([3, 2, 1]))

    print("===== jump2 =====")
    print(jump2([2, 3, 1, 1, 4]), end=" ")
    print(jump2([2, 3, 0, 1, 4]), end=" ")
    print(jump2([2, 1]), end=" ")
    print(jump2([3, 2, 1]))

    print("===== jump3 =====")
    print(jump3([2, 3, 1, 1, 4]), end=" ")
    print(jump3([2, 3, 0, 1, 4]), end=" ")
    print(jump3([2, 1]), end=" ")
    print(jump3([3, 2, 1]))

    print("===== jump4 =====")
    print(jump4([2, 3, 1, 1, 4]), end=" ")
    print(jump4([2, 3, 0, 1, 4]), end=" ")
    print(jump4([2, 1]), end=" ")
    print(jump4([3, 2, 1]))

    print("===== jump5 =====")
    print(jump4([2, 3, 1, 1, 4]), end=" ")
    print(jump4([2, 3, 0, 1, 4]), end=" ")
    print(jump4([2, 1]), end=" ")
    print(jump4([3, 2, 1]))

