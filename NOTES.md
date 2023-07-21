# Notes

## Rasterisation

A rasteriser draws primitives by testing which pixels overlap with it. It involves the projection of 3D images onto a flat screen.
This differs from a ray-tracer which calculates a ray from the camera position which passes through each different pixel and locates the intersection with the nearest primitive.

Rasterisation is comprised of two steps:

* Projecting vertices from primitives onto the screen using perspective projection, then each pixel is checked to see whether or not it is within the resultant 2D triangles. If they are, then the pixel takes the relevant colour.
