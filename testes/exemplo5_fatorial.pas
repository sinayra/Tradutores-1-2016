program Exe5;
(*Testando fatorial*)

var 
	x, f: integer;

begin
	read(x);
	if x >= 0 then
	begin
		f := 1;
		while x > 0 do
		begin
			f := f * x;
			x := x - 1;
		end
		write(f);
	end

end.