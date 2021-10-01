<div align="center">
	<a href="https://www.42sp.org.br/">
		<img src="../img/42-saopaulo.png">
	</a>
</div>


<h1 align="center"> Get_next_line </h1>

<h2 align="center">
	Project develop for <a href="https://github.com/LucasDatilioCarderelli/42Cursus"> 42Cursus </a>
</h2>

<p align="center">
  	<a href="https://www.linkedin.com/in/lucasdatiliocarderelli/">
    	<img alt="Linkedin" src="https://img.shields.io/badge/Lucas Datilio Carderelli-blue?style=flat&logo=Linkedin&logoColor=white" />
  	</a>
    <img src="https://img.shields.io/github/last-commit/LucasDatilioCarderelli/01-Get_next_line?color=blue">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/LucasDatilioCarderelli/01-Get_next_line?color=blue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/LucasDatilioCarderelli/01-Get_next_line?color=blue" />
</p>

<div align="center">
	<a alt="get next line" href="https://github.com/LucasDatilioCarderelli/01-Get_next_line">
		<img src="../img/gnl.png">
	</a>
</div>

## Goal
This project will not only allow you to add a very convenient function to your collection,
but it will also allow you to learn a highly interesting new concept in C programming:
static variables

### Description
` Write a function which returns a line read from a file descriptor `

### Prototype
```c
char *get_next_line(int fd);
```

### Parameters
` File descriptor to read from `

### Return
` Value Read line: correct behavior
NULL: nothing else to read or an error occurred; `

### External functs
```c
read(2)
malloc(3)
free(1)
```

## Bonus Part
To be able to manage multiple file descriptors with your get_next_line. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.
