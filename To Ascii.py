import sys
from PIL import Image
import os

chars = [x for x in "`^\",:;Il!i~+_-?[}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpbkhao*#MW&8%B@$"]
for i in os.listdir("C:\\Users\\joelh\\OneDrive\\Documents\\Rick Roll Project\\frames"):
    # pass the image as command line argument
    image_path = "C:\\Users\\joelh\\OneDrive\\Documents\\Rick Roll Project\\frames\\" + i
    img = Image.open(image_path)

    # resize the image
    width, height = img.size
    aspect_ratio = height / width
    new_width = 120 * 4
    new_height = aspect_ratio * new_width * 0.55
    img = img.resize((new_width, int(new_height)))
    # new size of image
    # print(img.size)

    # convert image to greyscale format
    img = img.convert('L')

    pixels = img.getdata()

    # replace each pixel with a character from array

    new_pixels = [chars[pixel // 4] for pixel in pixels]
    new_pixels = ''.join(new_pixels)

    # split string of chars into multiple strings of length equal to new width and create a list
    new_pixels_count = len(new_pixels)
    ascii_image = [new_pixels[index:index + new_width] for index in range(0, new_pixels_count, new_width)]
    ascii_image = "\n".join(ascii_image)
    print(i)

    # write to a text file.
    with open("C:\\Users\\joelh\\OneDrive\\Documents\\Rick Roll Project\\texts\\" + i[:-4], "w") as f:
        f.write(ascii_image)
