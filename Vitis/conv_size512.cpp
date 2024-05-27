#include <stdint.h>

// Define image dimensions
#define WIDTH 512
#define HEIGHT 512

void conv(uint8_t image_in[HEIGHT][WIDTH], uint8_t image_out[HEIGHT][WIDTH], char kernel[3][3]){
    // Control interface separate from data interfaces
    #pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS
    #pragma HLS INTERFACE s_axilite port=image_in bundle=CTRL_BUS
    #pragma HLS INTERFACE s_axilite port=image_out bundle=CTRL_BUS
    #pragma HLS INTERFACE s_axilite port=kernel bundle=CTRL_BUS

    // Data interfaces on different bundles
    #pragma HLS INTERFACE m_axi depth=262144 port=image_out offset=slave bundle=DATA_BUS
    #pragma HLS INTERFACE m_axi depth=262144 port=image_in offset=slave bundle=DATA_BUS

    #pragma HLS DATAFLOW

    // Perform convolution
    for(int y = 1; y < HEIGHT-1; y++){
        for(int x = 1; x < WIDTH-1; x++){
            int sum = 0;
            for(int ky = -1; ky <= 1; ky++){
                for(int kx = -1; kx <= 1; kx++){
                    sum += image_in[y+ky][x+kx] * kernel[ky+1][kx+1];
                }
            }
            // Truncate if sum is outside 0-255
            image_out[y][x] = (sum > 255) ? 255 : (sum < 0 ? 0 : sum);
        }
    }
}


