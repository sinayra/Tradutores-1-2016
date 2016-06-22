program Exe28;

var 
	a, c: boolean;
	b: integer;
begin
	a := true;
	c := true;
	if not a and c then 
	begin
		b := 4;
		write(1);
	end
	else
	begin
		b := 5;
		write(2);
	end
	write(b + 2);
end.