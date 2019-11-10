# Route optimization

This is a route optimization tool that I designed and implemented in 2014 as a course project. The tool can be used to search the fastest or least expensive route between two points on a map, given that the time or expense of each step is known. An example application for this tool is logistics planning in order to

* deliver goods in time
* minimize vehicle idle time
* reduce costs and CO<sub>2</sub> emissions by saving fuel

The algorithms behind the tool include [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) and [A<super>*</super>](https://en.wikipedia.org/wiki/A*_search_algorithm), both of which utilize a [min-heap](https://en.wikipedia.org/wiki/Binary_heap). The algorithms and data structures have been implemented from scratch using C++. The documentation is in Finnish.

To run the tool from the Linux command line, use the following syntax:
```
$ project/runApplication -algorithm -echoMode mapFileName startX startY endX endY
```

Example 1:
```
$ project/runApplication -d -on map.txt 0 0 29 29
```

Example 2:
```
$ project/runApplication -a -off map.txt 0 0 29 29
```

Running the unit tests:
```
$ project/runTests
```
