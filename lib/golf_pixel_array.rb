$gtk.ffi_misc.gtk_dlopen("golf_pixel_array")

module Golf
  attr_reader :w, :h
              #:c_pixel_array

  class PixelArray
    def initialize(x,y,width,height,scale,name="pixel_array")
      @c_pixel_array  = FFI::GolfPixelArray::new_pixel_array(width, height, name)

      @x, @y          = x, y
      @name = name

      @width          = width
      @height         = height

      @scale          = scale

      @render_width   = scale * width
      @render_height  = scale * height
    end

    def c_pixel_array
      @c_pixel_array
    end

    def render(args)
      FFI::GolfPixelArray::update_pixel_array(@c_pixel_array)

      args.outputs.primitives << [@x,
                                  @y,
                                  @render_width,
                                  @render_height,
                                  @name.to_sym].sprite
    end

    def c
      FFI::GolfPixelArray::clear_pixel_array(@c_pixel_array)
    end

    def gp(x,y)
      color = FFI::GolfPixelArray::get_pixel_at(@c_pixel_array,x,y);
      [color&0xFF, (color>>8)&0xFF, (color>>16)&0xFF]
    end

    def sp(x,y,red,green,blue)
      color = 0xFF000000 + (blue.to_i<<16) + (green.to_i<<8) + red.to_i
      FFI::GolfPixelArray::set_pixel_at(@c_pixel_array,x,y,color);
    end

    def cp(x,y,source,source_x,source_y,source_w,source_h)
      puts "source: #{source.c_pixel_array}"
      puts "dest(self): #{@c_pixel_array}"
      puts "x:#{x} - y:#{y} - sx:#{source_x} - sy:#{source_y} - sw:#{source_w} - sh:#{source_h}"
      FFI::GolfPixelArray::copy_area( source.c_pixel_array,
                                      @c_pixel_array,
                                      source_x,
                                      source_y,
                                      source_w,
                                      source_h,
                                      x, y )
    end
  end
end
