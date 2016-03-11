import sys
from PIL import Image

image = Image.open(sys.argv[1])

fishes = []
(w, h) = image.size
pixels = image.load()

for x in xrange(h):
    for y in xrange(w):

        average = 0
        for i in xrange(3):
            average += pixels[y, x][i]
        average /= 3

        if average < 128:
            fishes.append((x, y))

print h, w, len(fishes), 10000
for fish in fishes:
    print fish[0], fish[1]
