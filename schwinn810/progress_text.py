""" Simple text based progress indicator """

from __future__ import print_function

class TextProgress:

    def track(self, name, at, end, points):
        print("Fetching track {:s} [{:d}/{:d}] with {:d} points".format(name, at, end, points))

    def point(self, at, end):
        if at % 100 == 0:
            print("{:.0f}%".format(100.*at/end))
