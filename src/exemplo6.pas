var 
	a, b: integer;
	c: boolean;
begin
	while a < b do
	begin
		a := a + b;
		read ( a, b, c ) ;
		a := b
	end;

	a := c
end