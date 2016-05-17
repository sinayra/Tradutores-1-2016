program Exe9;

var 
	x, y: integer;
	a, b, c, d: boolean;

function func1() : integer;
begin
	a := 0.0;

	while a < 3.0 do
	begin
		a := a + 1.0;
		write(a);
	end

	func1 := a;
end;

function func2() : integer;
begin
	read(d);
	func2 := d;
end;

procedure func3();
begin
	write(a);
end;

begin
	b := b - a * c;

	read(x, y);
	a := func2();
	func3();
end.