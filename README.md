# dr_golf_pixel_array

A simple pixel array for DragonRuby.

## Setup:
```ruby
args.state.pxa        = Golf::PixelArray.new( 512, 232, # x and y position
                                              64, 64,   # width and height
                                              4 )       # scale
```
                                              
## Access pixels:
```ruby
# Set a pixel :
args.state.pxa.sp(32,32,0xFF0000FF)

# Get a pixel :
pv = args.state.pxa.gp(32,32)
```
