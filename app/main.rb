require 'lib/golf_pixel_array.rb'





################################################################################
# 1. SETUP :
################################################################################
def setup(args)
  args.state.pxa        = Golf::PixelArray.new( 512, 232, # x and y position
                                                64, 64,   # width and height
                                                4 )       # scale
  args.state.pxa.sp(32,32,0xFF0000FF)
  args.state.setup_done = true
end





################################################################################
# 2. MAIN LOOP :
################################################################################
def tick(args)
  setup(args) unless args.state.setup_done

  # !!! DON'T FORGET TO RENDER THE PIXEL ARRAY !!!
  args.state.pxa.render(args)
  # !!! DON'T FORGET TO RENDER THE PIXEL ARRAY !!!

end
