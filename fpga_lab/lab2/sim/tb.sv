module tb ();

    logic       user_btn_r;
    logic       user_btn_l;
    logic [6:0] seven_seg0;
    logic [6:0] seven_seg1;
    logic [6:0] seven_seg2;
    logic [6:0] seven_seg3;
    logic [6:0] seven_seg4;
    logic [6:0] seven_seg5;
    logic       clk50     ;

    always #10 clk50 = ~ clk50;

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

        repeat(10000) @(posedge clk50);
        $finish;
    
    end



endmodule