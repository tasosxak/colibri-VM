public class Object extends NULL:
	public I name;
        public I objectid;

	public virtual V init(R);
		sconst "Constructor Object"
		print
		rload_ 1
		iconst 555
		putfield objectid
                sconst "Fieldname:"
                print
                rload_ 1
                getfield objectid
                invoke_virtual Object toString
                print
		iconst 0
		iconst 1
		ret

	public virtual I equals(R,R);
		rload_ 2
		getfield name
		rload_ 1
		getfield name
		icmp
		ifeq equal notequal
		equal:
		iconst 0
		jmp end
		notequal:
		iconst -1
		end:
		iconst 2
		ret

	public native R toString(R);
        public native B equals(R,R);

endclass


final class Person extends Object:
	public I age;

	public virtual V init(I,R);
		rload_ 1
                invoke_virtual Object toString
		print
		rload_ 2
		invoke_special Object init
		pop
		sconst "Constructor Person"
		print
		rload_ 2
		iload_ 1
		putfield age
		iconst 0
		iconst 2
		ret
        public native V helloworld(R);
	
endclass

Person pr = NULL;

V main();
	new Person
	dup 2
	iconst 12
	invoke_virtual Person init
	pop
	rstore pr
	rload pr
	getfield name
        invoke_virtual Object toString
	print
	rload pr
	invoke_virtual Person toString
	print
        rload pr
        rload pr
        invoke_virtual Object equals
        invoke_virtual Person toString
        print
        rload pr
        invoke_virtual Person helloworld
	iconst 0	
	iconst 0
	ret


invoke_static main
pop