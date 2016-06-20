program Exe8;
var 
	x, y: integer;
	a, b, c: boolean;
begin
	a := 1;
	b := 2;
	while a or b do
	begin
		if not a then
		begin
			if not (x >= y) then
				b := (b - a) * c;
			a := b div x;
		end
		else
		begin
			b := a + c;
			if not x and not y then 
				x := a;
			else 
				y := b;
			y := not(a * b);
		end
	end
	read(x);
end.