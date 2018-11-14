# Colibri VM (alpha)

Colibri Virtual Machine (CVM) is an open source stack-based virtual machine for executing programs written in Nectar. 

![coral system](https://github.com/tasosxak/CoralVM/blob/master/colibri_architecture.png)

# Installing

Building the virtual machine is this easy:

```
   $ git clone https://github.com/tasosxak/colibri-VM.git
   $ cd colibri-VM
   $ make
```
That's it.

# Running CVM

After you have setup the local installation of CVM, you can now run bytecode:

```
   $ cd dist/Debug/GNU-Linux
   $ ./colibrivm test.cex
```

# Example

For example this is a very simple bytecode(colibri executable) program that prints out "Hello World":

```
virtual V main();
      sconst "Hello World"
      print
      nl
      iconst 0
      ret
      end_func
     
   ```

Save this in the same directory as the colibrivm , as `helloworld.cex`. Then run the VM:

```
   $ colibrivm helloworld.cex
```
And the output is : 

```
   $ Hello World
   $ 
   
```

# Bytecode commands
istore   dstore   fstore   sstore   rstore   iastore  istore_   dstore_  fstore_ sstore_  rstore_  iload_   dload_   sload_   fload_   rload_   iload dload fload iaload   ivar  dvar svar fvar iconst dconst fconst sconst rconst_null pop iadd dadd fadd sadd  isub dec inc  dsub fsub  ssub imul dmul smul fmul idiv ddiv fdiv sdiv i2s i2d i2f d2i d2s d2f f2d s2i s2d s2f ret new invoke_virtual invoke_static print read nl putfield getfield dup icmpg icmp dcmp ifzero ifnotzero ifeq ifne ifg ifge ifl ifle ifnull ifnotnull jmp newarray



# Contributing

You may contribute in several ways like fixing bugs, improving documentation and examples or translating any document here to your language. 

