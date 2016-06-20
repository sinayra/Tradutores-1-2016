<<<<<<< HEAD
program Exe13;

var 
	a, b: integer;

begin
	read(a,b);
	write(a,b);
	
	read(a);
	write(a);
	
	b := a + 2;
	write(b);
end.

=======
program Exe15;

var 
	a, b, aux: integer;

begin
	a := 1;
	b := 1;
	
	while b < 11 do
	begin
		a := 1;
		while a < 11 do
		begin
			aux := a * b;
			write(aux);
			a := a + 1;
		end
		b := b + 1;
	end
end.
>>>>>>> f92a5a50635f9404c4257c8754a933fe0eda8524
