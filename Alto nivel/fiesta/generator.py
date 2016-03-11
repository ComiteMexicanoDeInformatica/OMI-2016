import sys, random

type = sys.argv[1]
n = int(sys.argv[2])
p = float(sys.argv[3])

edges = [[0 for i in xrange(n)]
            for j in xrange(n)]

for i in xrange(n):
    for j in xrange(n):
        if i == j: continue
        if random.random() <= p:
            edges[i][j] = 1

if type == 'force':
    m = int(sys.argv[4])
    for k in xrange(m):

        cool = random.randint(0, n - 1)
        for i in xrange(n):
            if i == cool: continue
            edges[cool][i] = 0
            edges[i][cool] = 1

if type == 'fakes':
    m = int(sys.argv[4])
    for k in xrange(m):

        fake = random.randint(0, n - 1)
        for i in xrange(n):
            if i == fake: continue
            if random.random() < 0.99:
                edges[fake][i] = 0
                edges[i][fake] = 1

print n
for i in xrange(n):
    buffer  = ''
    for j in xrange(n):
        buffer += '%d ' % edges[i][j]
    print buffer
