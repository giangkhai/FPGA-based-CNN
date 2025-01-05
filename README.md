# Convolution IP Core Project

This repository contains files for creating and testing a Convolution IP Core using Vitis and PYNQ overlays.

## Contents

- *Vitis Folder*: Contains `.cpp` files to create the Convolution IP Core.
- *Jupyter Notebook Folder*: Contains `.hwh`, `.tcl`, and `.bit` files generated in Vivado, as well as test image files.
- *Test Image Files*: Sample images for testing the Convolution IP Core.

## Usage

### 1. Creating the Convolution IP Core in Vitis

1. Place the `.cpp` files in the Vitis folder.
2. Use these files to create an IP core.
3. Utilize the created IP core to design the block diagram.
4. Generate the `.hwh`, `.tcl`, and `.bit` files.

### 2. Using Pre-generated Files

If you prefer to use the pre-generated files, follow these steps:

1. Copy the included `.hwh`, `.tcl`, and `.bit` files.
2. Place these files in the `/xilinx/pynq/overlays` directory on your PYNQ board.

### 3. Running the Test Cases

1. Open the Jupyter Notebooks provided in the repository.
2. Run the notebooks to test the Convolution IP Core using the included test images.
3. Observe the results to verify the functionality.

## Tips
- You can add new images with any name in the `image` folder.
- You can change the 3x3 kernel in the path. However, with the limitation of 1 pixel represented by 8 bits, the pixel value ranges from 0 to 255. If it exceeds these bounds, the pixel will automatically update to the nearest boundary value.

## Note
- Change the path name in the PS + PL source code, and PS for the image you want to process.
- Pixels here are in `char` format, so the kernel in `float` format can lead to undesirable results.
## RTL guide note
- Add `muladdtree3x3.v`, `line_buffer.v` in your project, choose `project manager > Add sources > Add or create design sources`.
- Add `combined_tb.v` in your project, choose  `project manager > Add sources > Add or create design sources`.
  ## Contributors
- Project by: Khai Giang-Mien and Nguyen Phan-Nguyen-Khoi
