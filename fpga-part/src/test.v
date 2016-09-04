`include "uart_transmitter.v"


`define WORDSIZE 16
reg [1:`WORDSIZE] data;
`timescale 1 ns/ 100 ps

module disp;
reg [31:0] rval;
initial
begin
rval = 101;
$display("rval = %h hex %d decimal", rval, rval); // auto new line
$write("rval = %h hex %d decimal\n", rval, rval); // new line by '\n', '%m'->printf module name
$monitor("..."); // output variable parameter
end
endmodule


initial // no delay
begin
data = 1; 
// only execute once
end

initial // assign 1 to data when 5 clock
begin
#5 data = 1; 
// only execute once
end

initial // no delay
begin
data = 1; 
#5 data = 1;
// only execute once
end


always 
begin
data = 0; 
// execute permanently
end

/************************
always clock = ~clock; // super loop when 0 clock

always #100 clock = ~clock; // create a 50MHZ clock 

always @ (posedge clock); // execute when posedge come

always @ (sel or a or b or c); // execute when signal changed 

************************/

fork
// parallel block
join

if(1)
begin
$display("123");
end
else

case(data)
	1: data=0;
	2: data=1;
	default: data=2;
endcase

casez
endcase

casex
endcase

module
task light;


endtask
endmodule

