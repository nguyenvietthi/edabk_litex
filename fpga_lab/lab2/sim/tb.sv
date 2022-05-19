`timescale 1ps/1ps
module tb();

    logic       user_btn_r;
    logic       user_btn_l;
    logic [6:0] seven_seg0;
    logic [6:0] seven_seg1;
    logic [6:0] seven_seg2;
    logic [6:0] seven_seg3;
    logic [6:0] seven_seg4;
    logic [6:0] seven_seg5;
    logic       clk50     ;

    always #1 clk50 = ~ clk50;

    top dut(
        .user_btn_r (user_btn_r),
        .user_btn_l (user_btn_l),
        .seven_seg0 (seven_seg0),
        .seven_seg1 (seven_seg1),
        .seven_seg2 (seven_seg2),
        .seven_seg3 (seven_seg3),
        .seven_seg4 (seven_seg4),
        .seven_seg5 (seven_seg5),
        .clk50      (clk50     )        
    );

    initial begin
        user_btn_r = 'b0;
        user_btn_l = 'b0;
        clk50      = 'b0;
    end

    always @(*) begin 
      if (!(seven_seg5 | seven_seg4 | seven_seg3 | seven_seg2 | seven_seg1 | seven_seg0)) begin 
        $display("%d%d:%d%d:%d%d\n",convert(seven_seg5),convert(seven_seg4),convert(seven_seg3),convert(seven_seg2),convert(seven_seg1),convert(seven_seg0));
      end
    end

  function logic[3:0] convert (logic[6:0] segment);
    case (~segment)
      7'b0111111: return 4'h0;
      7'b0000110: return 4'h1;
      7'b1011011: return 4'h2;
      7'b1001111: return 4'h3;
      7'b1100110: return 4'h4;
      7'b1101101: return 4'h5;
      7'b1111101: return 4'h6;
      7'b0000111: return 4'h7;
      7'b1111111: return 4'h8;
      7'b1101111: return 4'h9;
      7'b1110111: return 4'ha;
      7'b1111100: return 4'hb;
      7'b0111001: return 4'hc;
      7'b1011110: return 4'hd;
      7'b1111001: return 4'he;
      7'b1110001: return 4'hf;
    endcase  
  endfunction 

endmodule