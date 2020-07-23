from functools import reduce

def convex_hull_graham(points):
    TURN_LEFT, TURN_RIGHT, TURN_NONE = (1, -1, 0)

    def cmp(a, b):
        return (a > b) - (a < b)

    def turn(p, q, r):
        return cmp((q[0] - p[0])*(r[1] - p[1]) - (r[0] - p[0])*(q[1] - p[1]), 0)

    def _keep_left(hull, r):
        while len(hull) > 1 and turn(hull[-2], hull[-1], r) == TURN_RIGHT :
            hull.pop()
        if not len(hull) or hull[-1] != r:
            hull.append(r)
        return hull

    points = sorted(points)
    l = reduce(_keep_left, points, [])
    u = reduce(_keep_left, reversed(points), [])
    return l.extend(u[i] for i in range(1, len(u) - 1)) or l

def main() :
    for _ in range(int(input())) :
        n,q = list(map(int,input().split()))
        original_points = [ list(map(int,input().split())) for _ in range(n) ]
        for Q in range(q) :
            nept = list(map(int,input().split()))
            v1 = original_points.copy()
            v1.append(nept)
            f = 1
            deli = 0 
            while f :
                poly = convex_hull_graham(v1)
                if (poly==v1) :
                    print('incons')
                    break
                if nept in poly :
                    f = 0
                    break
                v1 = [item for item in v1 if item not in poly]
                deli += 1
            print(deli)
