$gtk.ffi_misc.gtk_dlopen("golf_pixel_array")

module Golf
  attr_reader :w, :h
  class PixelArray
    def initialize(x,y,width,height,scale)
      FFI::GolfPixelArray::bridge_init_pixel_array(width, height)

      @x, @y          = x, y

      @width          = width
      @height         = height

      @scale          = scale

      @render_width   = scale * width
      @render_height  = scale * height
    end

    def render(args)
      FFI::GolfPixelArray::bridge_update_pixel_array

      args.outputs.primitives << [@x,
                                  @y,
                                  @render_width,
                                  @render_height,
                                  :pixel_array].sprite
    end

    def c
      FFI::GolfPixelArray::bridge_clear_pixel_array
    end

    def gp(x,y)
      FFI::GolfPixelArray::bridge_get_pixel_at(x,y);
    end

    def sp(x,y,color)
      FFI::GolfPixelArray::bridge_set_pixel_at(x,y,color);
    end
  end
end
