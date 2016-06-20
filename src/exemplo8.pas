program Exe8;
var 
	x, y: integer;
	a, b, c: boolean;
begin
	a := 1;
	b := 2;
	while a < b do
	begin
		if a < b then
		begin
			if x > y then
				b := (b - a) * c;
		end
		else
		begin
			b := a + c;
			if x > y then 
				x := a;
			else 
				y := b;
		end
	end
	read(x);
end.