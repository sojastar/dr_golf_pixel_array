$gtk.ffi_misc.gtk_dlopen("golf_pixel_array")

module Golf
  attr_reader :w, :h
  class PixelArray
    def initialize(x,y,width,height,scale)
      @c_pixel_array    = FFI::GolfPixelArray::new_pixel_array(width, height)

      @x, @y          = x, y

      @width          = width
      @height         = height

      @scale          = scale

      @render_width   = scale * width
      @render_height  = scale * height
    end

    def render(args)
      FFI::GolfPixelArray::update_pixel_array(@c_pixel_array)

      args.outputs.primitives << [@x,
                                  @y,
                                  @render_width,
                                  @render_height,
                                  :pixel_array].sprite
    end

    def c
      FFI::GolfPixelArray::clear_pixel_array(@c_pixel_array)
    end

    def gp(x,y)
      FFI::GolfPixelArray::get_pixel_at(@c_pixel_array,x,y);
    end

    def sp(x,y,color)
      FFI::GolfPixelArray::set_pixel_at(@c_pixel_array,x,y,color);
    end
  end
end
