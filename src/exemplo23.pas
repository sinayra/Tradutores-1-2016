program Exe23;

var 
<<<<<<< HEAD
	a, b: integer;

begin
	read(a,b);
	
	if (a > 10) and (b < 10) then
	begin
		write(a,b);
	end

	
=======
	a: integer;
	b: boolean;

begin
	a := 5;
	b := true;

	if 1 < 2 then
		a := -5;

<<<<<<< HEAD
	write(a);
>>>>>>> 7bf89e855c7a1f1b084376c2f63af16d8940afa6
=======
	write(a, a * a, 6);
	write(2);
>>>>>>> ca0bfd3741d6fa7a7cb4ab0b8a54722a89c11685
end.