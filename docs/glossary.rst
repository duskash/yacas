========
Glossary
========
.. glossary::
  arity 
       Arity is the number of arguments of a function.  For example,
       the function :func:`Cos` has one argument and so we say that
       :func:`Cos` *has arity 1*.  Arity of a function can be 0, 1, 2, ...

       Yacas allows to define functions with the same name but
       different arities, and different rules corresponding to these
       arities will be used.  Also, it is possible to define a
       function with optional arguments, for example, :func:`Plot2D` is one
       such function.  Such functions can have any arity larger or
       equal to a certain minimum arity (the number of non-optional
       arguments).

       .. seealso:: :func:`Function`, :func:`OpPrecedence`,
                    :func:`Rule`

  array
    An array is a container object that can hold a fixed number of
    other Yacas objects in it.  Individual elements of an array can
    be accessed using the {[]} operation.  Most list operations also
    work on arrays.

    Arrays are faster than lists but the array size cannot be
    changed.

    .. seealso:: :func:`Array'Create`

  atom
    Atoms are basic Yacas objects that are used to represent symbols,
    numbers, and function names.  An atom has a string representation
    which is shown when it is displayed.  For example, {3.14159},
    {x}, {A123}, {+}, {"good morning"} are atoms.

    Atoms can be of type string, number, or symbol. For example, {y1}
    is a symbolic atom, {954} is a number atom, and {""} is an
    (empty) string atom.  Symbolic atoms are normally used in yacas
    to denote mathematical unknowns and function names. Number and
    string atoms are used to denote values.

    A symbolic atom can be bound to a value (in which case it becomes
    a variable), or to a rule or several rules (in which case it
    becomes a function).  An atom can also have a property object.

    .. seealso:: :func:`Atom`, :func:`String`

  bodied function

   *Bodied functions* have all arguments except the first one inside
   parentheses and the first argument outside the argument list, for
   example::

     Integrate(x) Sin(x);

  CAS
    Abbreviation for "computer algebra system". Yacas is a CAS.


  constant
  cached constant
    Constants such as :data:`Pi` or :data:`GoldenRatio` are symbolic atoms
    that are specially interpreted by yacas.  For example, there
    are simplification rules that transform expressions such as
    ``Sin(Pi)`` into ``0``.  When requesting a numerical evaluation of a
    constant, the numerical value is given to the current value as
    set with :func:`N`.

    Some constants take a long time to compute and therefore they are
    cached at the highest precision computed so far.  These are the
    `cached constants`.

    .. seealso:: :func:`N`, :func:`CachedConstant`, :data:`Pi`,
                 :data:`GoldenRatio`, :data:`CatalanConstant`,
                 :data:`gamma`

  equation 
    To denote symbolic equations, the operator {==} is used.  This
    operator does not assign or compare its sides.  For example, the
    expression {Sin(x)==1} is kept unevaluated and can be passed as
    argument to functions.  For example, In> Solve(Sin(x)==1, x) Out>
    {x==Pi/2};

    The symbolic equation operator {==} is also useful to represent
    solutions of equations or to specify substitutions, give options,
    and so on.

    .. seealso:: :func:`Solve`, :func:`Where`, :func:`Plot2D`

  function
    A function is a symbolic atom that is bound to a rule or several
    rules.  A function can have none, one, or more arguments.
    Functions can also have a variable number of arguments.
    Arguments of functions are arbitrary Yacas objects.

    Functions can be evaluated, that is, the rules bound to them may
    be executed.  For example, ``Cos(Pi+0)`` is an expression that
    contains two functions and four atoms.  The atom ``Pi`` is a
    symbolic atom which is normally not bound to anything.  The atom
    ``0`` is a numeric atom.

    The atoms ``Cos`` and ``+`` are symbolic atoms which are bound to
    appropriate simplification rules.  So these two atoms are
    functions.  Note that these functions have different syntax.
    ``Cos`` is a normal function which takes its arguments in
    parentheses.  The atom ``+`` is a function with special syntax
    because ``+`` is placed between its arguments and no parentheses
    are used.

    The rules to which ``+`` is bound are such that the expression
    ``Pi+0`` is evaluated to the symbolic atom ``Pi``.  The rules for
    ``Cos`` are such that the expression ``Cos(Pi)`` is evaluated to
    the numeric atom ``-1``.  The example yacas session is::

      In> Cos(Pi+0)
      Out> -1

    Some functions are built-in and implemented in C++, while others
    are library functions.

    The built-in functions are usually less flexible than the library
    functions because they cannot be left unevaluated.  Given
    incorrect arguments, a built-in function will generate an error.
    However, a user-defined function may simply return unevaluated in
    such cases.


    .. seealso:: :func:`Function`, :func:`Rule`, :func:`<--`

  list
    A list is a basic yacas container object. A list is written as
    e.g. ``{{a, b, c}}`` or ``{{}}`` (empty list).  Individual elements of a
    list can be accessed using the ``[]`` operation.  Lists can be
    concatenated, and individual elements can be removed or inserted.

    Lists are ubiquitous in yacas.  Most data structures in the
    standard library is based on lists.

    Lists are also used internally to represent yacas expressions.
    For example, the expression ``Cos(x+1)`` is represented internally
    as a nested list::

        In> FullForm( Cos(x+1) )
        (Cos (+ x 1 ))
        Out> Cos(x+1);


    .. seealso:: :func:`List`, :func:`Listify`, :func:`UnList`,
                 :func:`Length`, :func:`FullForm`

  matrix
    A matrix is represented as a list of lists.  Matrices are
    represented in the *row-major* order: a matrix is a list of rows,
    and each row is a list of its elements.

    Some basic linear algebra operations on matrices are supported.

    .. seealso:: :func:`Determinant`, :func:`Identity`,
                 :func:`IsDiagonal`, :func:`EigenValues`

  operator
    Operators are functions that have special syntax declared for
    them.  An operator can be *bodied*, infix, prefix or postfix.
    Because of this, operators must have precedence.

    Apart from the syntax, operators are exactly the same as any
    other functions, they can have rules bound to them in the same
    way.

    .. seealso:: :func:`Bodied`, :func:`Infix`, :func:`Prefix`,
                 :func:`Postfix`

  precedence
    Precedence is a property of the syntax of an operator that
    specifies how it is parsed.  Only operators, i.e. functions with
    special syntax, can have precedence.  Precedence values are
    nonnegative integers: 0, 1, ...  Lower numbers bind more tightly.

    For example, the operator ``+`` binds less tightly (i.e. has a
    *higher* precedence value) than the operator ``*`` and so
    the expression ``a+b*c`` is parsed as ``a+(b*c)``, as one would
    expect.

    Infix operators can have different left-side and right-side
    precedence -- this allows us to parse
    expressions such as :math:`a-b+c` correctly, as :math:`(a-b)+c`, and not as
    :math:`a-(b+c)`.

    .. seealso:: :func:`Bodied`, :func:`OpPrecedence`,
                 :func:`OpLeftPrecedence`, :func:`OpRightPrecedence`

  property
    Properties are special additional objects (tags) that can be tied
    to expressions.  For example, the expression {1+x} may be tagged
    by an expression {y} by the command ::

      In> a:= ExtraInfo'Set(1+x,y);
      Out> 1+x;
    
    Now ``a`` refers to an expression ``1+x`` which is different from all
    other copies of ``1+x`` because it is tagged by ``y``.

    .. seealso:: :func:`ExtraInfo'Get`, :func:`ExtraInfo'Set`

  rule
    Rules are the principal mechanism of expression evaluation in
    yacas.  A rule specifies that a certain symbolic expression is
    to be replaced by another expression.  If no rule that matches a
    given symbolic expression can be found, the expression is left
    unevaluated.  This is usually the desired behavior for a CAS.  For
    example, a user can type ::

      In> func1(x+0)
      Out> func1(x);

    and use an undefined function {func1}.  Since no rules are defined
    for the function {func1}, it is not evaluated, but its argument
    has been simplified.

    Only expressions containing functions can be evaluated by rules.
    (Atoms are evaluated only if they are bound to a value.)

    Several rules can be defined for a given function.  Rules can be
    erased or added at run time.

    .. seealso:: :func:`Rule`, :func:`<--`, :func:`Retract`

  string
    A string is an atom with character string value, for example,
    ``"abcd"``.  Individual characters of the string can be accessed
    using the ``[]`` operation.  Some string manipulation functions are
    supported.

    .. seealso:: :func:`String`, :func:`StringMid'Get`,
                 :func:`StringMid'Set`

  syntax
    Yacas uses an infix syntax similar to C or Fortran.  However,
    the syntax is entirely user-defined and very flexible.  Infix,
    prefix, postfix operators can be defined, as well as "bodied"
    functions.  This allows to write mathematical expressions more
    comfortably, for example ::

      In> D(x) Sin(x)+1
      Out> Cos(x);

    Functions with special syntax can have different precedence.

    .. seealso:: :func:`Bodied`, :func:`Infix`, :func:`Prefix`,
                 :func:`Postfix`, :func:`OpPrecedence`

  threaded function
    Threaded function applied to a list ::
    
        In> Cos({Pi/2, Pi/4})
        Out> {0,Sqrt(1/2)} 

  variable
    Variables are symbolic atoms bound to a "value".  Value is any
    Yacas object, such as an atom or a list.  For example, after
    executing ::

      In> a := 1
      Out> 1;

    the symbolic atom {a} becomes a variable bound to a value, the
    numeric atom {1}.

    .. seealso:: :func:`Eval`, :func:`:=`, :func:`Clear`

  warranty
    Yacas is Free Software (*logiciel libre*) and comes with **NO
    WARRANTY**.  See :ref:`lgpl-2.1` for more information.
