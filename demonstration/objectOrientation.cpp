  
/* OBJECT ORIENTED PROGRAMMING:
 * ============================
 * So far, we have written code using a PROCEDURAL paradigm. Fundamentally, 
 * this involves writing functions (or procedures) that operate on data that 
 * is passed to them, or simply writing code that operates on programatic 
 * data at global scope.
 *
 * While C++ MAY be used to program procedurally, it is actually DESIGNED to 
 * enable an OBJECT ORIENTED programming paradigm. OBJECT ORIENTED programs
 * describe programatic operations as the interaction between ENCAPSULATED 
 * OBJECTS. OBJECTS can be made to operate upon their own INTERNAL DATA, as well * as EXTERNAL DATA that are supplied to them, OFTEN in the form of OTHER
 * OBJECTS.
 *
 * OBJECT ORIENTED programs in C++ can be BROADLY SEGREGATED into two distinct
 * parts. The first part describes the PROPERTIES and BEHAVIOURS of the 
 * OBJECTS that will comprise the program. The second part describes the 
 * INTERACTIONS between the objects described in the first part.  
 */

/* CLASSES:
 * ========
 * A CLASS in C++ is a programatic DESCRIPTION of a TYPE of OBJECT. Indeed,
 * DEFINING a new class implicitly defines a new TYPE in C++.
 * 
 * To DECLARE a new class of object in C++ we use the "class" KEYWORD in 
 * conjunction with an IDENTIFIER which names the class e.g.  
 */
class FirstClass;

/* Until a DEFINITION of the class is provided, the IDENTIFIER FirstClass
 * refers to an INCOMPLETE TYPE.
 * A class DEFINITION also uses the "class" KEYWORD and an IDENTIFIER, but
 * the identifier must be followed by a code block that surrounds a 
 * description of the class's properties and behaviours.
 * NOTE: The code block MUST be followed by a semicolon.
 *
 * The following snippet provides a MINIMAL definition for FirstClass.
 */
class FirstClass {
  
  // Description of class properties and behaviours.

}; // NOTE: Semicolon is required

/* FirstClass now refers to a COMPLETE TYPE and hereafter FirstClass is
 * a LEGAL TYPE SPECIFICATION. However, FirstClass specifies a type that 
 * doesn't actually do anything useful!
 */

/* THE CLASS DEFINITION - MEMBER DATA:
 * ===================================
 * C++ objects use MEMBER DATA to maintain a representation of their own 
 * INTERNAL STATE. Typically, this state is initialized, mutated internally
 * references and sometimes externally queried as part of a C++ program's 
 * operation.
 *
 * The MEMBER DATA that encoding the state of a SPECIFIC TYPE of C++ object 
 * are described within a CLASS DEFINITION using a series of C++ VARIABLE 
 * DECLARATION STATEMENTS. 
 *
 * The following definition of a class called NameAndNumber specifies a 
 * type with a state consisting of two MEMBER DATA - an integer and a string. 
 *
 * NOTE: A separate class declaration is not REQUIRED. A class definition
 * implicitly DECLARES that class. 
 */

// include the string header file to provide the std::string type 
#include <string>

// Definition of NameAndNumber  - a simple class with two DATA MEMBERS
class NameAndNumber {

  // A numeric integer representation of the class
  int classNumber;
  // A textual string representation of the class
  std::string className;
  
};

/* ACCESS SPECIFIERS:
 * ==================
 * It's not obvious, but as defined (and by default) the data members of 
 * NameAndNumber and those of any other SIMILARLY SPECIFIED class 
 * CANNOT BE REFERENCED by any C++ code outside of the class definition.
 *
 * This is a DESIGN FEATURE of C++ known as DATA ENCAPSULATION. It is 
 * designed to RESTRICT DIRECT EXTERNAL ACCESS to the data defining an 
 * object's internal state.
 *
 * Data encapsulation can be configured and overridden using ACCESS
 * SPECIFIERS. C++ defines THREE access specifiers. 
 *
 * - The default behaviour corresponds to the "private" access specifier 
 * and SHOULD TYPICALLY BE RETAINED for DATA MEMBERS.
 * 
 * - The OPPOSITE of the "private" access specifier is "public". Specifying
 * public access MAXIMALLY VIOLATES data encapsulation and SHOULD BE AVOIDED
 * where possible. Data memebers with public access can be referenced by ANY
 * C++ code that maintains a reference to the object itself.
 *
 * - The THIRD access specifier is "protected". This provides an INTERMEDIATE
 * LEVEL of access restriction that allows a SPECIFIC SUBSET of objects
 * to reference the data that are specified with this access level (See the 
 * later section on INHERITENCE.) 
 *
 * The following definition of a class called ContactDetails specifies
 * data members with different levels of access. The access level is specified
 * using the appropriate keyword (public, private or protected followed by a 
 * ":" token. All subsequently declared data members assume the specified 
 * access level until another access specifier statement is encountered.
 */

/* Definition of ContactDetails - a class with DATA MEMBERS having
 * Different access specifiers.
 */
class ContactDetails {

  /* NOTE: any data members declared here WOULD assume the DEFAULT
   * "private" access.
   */
  
public: // subsequent data members will have public access
  
  // The contact's phone number
  int phoneNumber;
  // The contact's surname
  std::string surname;
  // The contact's other name(s) - Will 5 be enough?
  std::string otherNames[5];

private: // subsequent data members have private access

  // The contact's address
  std::string addressLines[5];
};

/* THE CLASS DEFINITION - METHODS:
 * ===============================
 * C++ objects use METHODS to OPERATE INTERNALLY upon their data members,
 * provide FUNCTIONALITY and expose PRIVATE DATA MEMBERS via an EXTERNAL
 * INTERFACE.
 * 
 * Fundamentally, METHODS are simply functions that are delcared within a 
 * class definition and may directly reference the DATA MEMBERS declared
 * within the class definition, REGARDLESS OF THE DATA MEMBER'S access 
 * specifier.
 *
 * Methods can also have access specifiers applied to them. PUBLIC methods
 * can be called by any C++ code that maintains a reference to the object.
 * PRIVATE methods can only be called by methods of the oject itself.
 *
 * The following definition of a class called ContactDetailsHandler
 * illustrates HOW METHODS ARE DELARED within a class definition.
 * it also illustrates TWO VALID WAYS to DEFINE methods in C++.
 *
 * In C++, VERY SIMPLE methods are often defined WITHIN THE CLASS 
 * DEFINITION. MORE INVOLVED methods are USUALLY DECLARED SEPARATELY
 *  - often in a SEPARATE FILE.
 */

// include the iostream header to enable terminal output
#include <iostream>

/* Definition of ContactDetailsHandler - a class with METHODS to provide
 * access to private member data and print a summary of the contact's
 * details. 
 */
class ContactDetailsHandler {
  
public: // subsequent methods will have public access
  
  // "GETTER" method to retrieve the contact's phone number
  int getPhoneNumber(){
    // NOTE: Methods can reference and return private data members
    return phoneNumber;
  }

  // "SETTER" method to set the contact's phone number
  void setPhoneNumber(int phoneNumberArg){
    /* NOTE: Avoid SHADOWING the data member identifier with the argument
     * name.
     */
    phoneNumber = phoneNumberArg;
  }
  
  // OTHER GETTER AND SETTER methods ...

  /* Method returns the contact's address. Delegates functionality to a
   * private method.
   */
  std::string getAddress(){
    // NOTE: Methods can call private methods and return their results.
    return getAddressAsString();
  }

  /* This method sets the lines of the contact's address.
   * Its DEFINITION is NOT included in the class definition.
   */
  void setAddress(std::string * addressLinesArg, int numAddressLinesArg);

  // Some PUBLIC member data:
  // The contact's surname
  std::string surname;
  // The contact's other name(s) - Will 5 be enough?
  std::string otherNames[5];
  
  // Specify that all other member data have private access.
private: 
  // The contact's phone number
  int phoneNumber;
  // The contact's address
  std::string addressLines[5];
  // The number of lines in the contact's address
  int numAddressLines;

  /* A PRIVATE method that concatenates all the elements of addressLines
   * into a single, comma-separated string.
   * Its DEFINITION is NOT included in the class definition.
   */
  std::string getAddressAsString();

}; // END OF CLASS DEFINITION FOR ContactDetails.

/* A definition of a method OUTSIDE OF THE CLASS DEFINITION uses
 * resembles the in-class declaration except that the METHOD IDENTIFIER
 * MUST EXPLICITLY SPECIFY THE CLASS NAME  as a prefix, separated by the 
 * SCOPE RESOLUTION OPERATOR "::".
 */
std::string ContactDetailsHandler::getAddressAsString(){
  // Declare and initialize return value.
  std::string addressAsString = "";
  /* loop over non-empty address lines and assemble a comma-separated
   * string.
   */
  int addressLine(0);
  while(addressLine < numAddressLines - 1){
    // When used with string-type arguments the += operator performs
    // string concatenation.
    addressAsString += (addressLines[addressLine] + ", ");
    // increment the address line
    addressLine++;
  }
  // append the final line without a comma.
  addressAsString += addressLines[addressLine];

  // return the assembled string.
  return addressAsString;
}

// This method updates the contact's address to reflect the method arguments.
void ContactDetailsHandler::setAddress(std::string * addressLinesArg, int numAddressLinesArg){
  // Set the number of non-empty lines in the address
  numAddressLines = numAddressLinesArg;
  /* Copy the non-empty address lines from the method argument to
   * The member datum.
   */
  for(int addressLine = 0; addressLine < numAddressLines; ++addressLine){
    addressLines[addressLine] = addressLinesArg[addressLine];
  }
}

/* CONSTRUCTORS AND DESTRUCTORS:
 * =============================
 * A CONSTRUCTOR is a SPECIAL METHOD that serves to INITIALIZE the
 * state of a C++ object. This can include setting the values of 
 * member data, allocating memory for pointer-type variables, or 
 * verifying the availability of required resources.
 * 
 * A CONSTRUCTOR DECLARATION is UNUSUAL for two reasons:
 * - Its IDENTIFIER MUST be IDENTICAL to the name of the class. 
 * - Furthermore, the constructor declaration DOES NOT include
 * a RETURN TYPE specification. In fact the return type of a 
 * constructor is IMPLICITLY the type of the object it initializes.
 *
 * DESTRUCTOR methods are called automatically when an the last
 * reference to an object is about to go out of scope. They are
 * typically used to release or free any resources that were 
 * acquired or allocated during the object's lifetime.
 *
 * DESTRUCTOR DECLARATIONS are also unusual:
 * - Like constructors, the destructor declaration DOES NOT include
 * a RETURN TYPE specification. A destructor does not return a value.
 * - The destructor's IDENTIFIER MUST be IDENTICAL to the name of 
 * the class with a "~" character prepended.
 *
 * The Vector class defines a constructor that initializes its 
 * data members according to the constructor's arguments as well
 * as a destructor that frees memory allocated to store the 
 * vector component data. 
 */

// A class modelling an vector with arbitrary dimensionality.
class Vector {

  /* The following data members implicitly assume the DEFAULT private
   * access specifier.
   */

  // Dynamically allocated array of Vector components
  double * components;

  // The number of Vector components 
  unsigned int numComponents;
  
  // Specify public access to subsequently declared/defined methods
public :

  /* DECLARATION of a constructor with two parameters corresponding 
   * respectively to an array of double precision real-valued components 
   *and the number of elements comprising that array.  
   *
   * The method specifies no return type and specifies the class name
   * Vector as its identifier.
   */
  Vector(double componentsArg[], unsigned int numComponentsArg);

  /* DECLARATION and IN-CLASS DEFINITION of the class DESTRUCTOR.
   * The destructor prevents memory leaks by deallocating memory
   * that was allocated using the new[] operator.
   */
  ~Vector(){
    // Release the memory that was allocated for the vector components.
    delete[] components;
  }
  
};

// Out of class definition of the constructor for the Vector class.
/* NO RETURN TYPE */ Vector::Vector(double componentsArg[],
				    unsigned int numComponentsArg){
  // initialize member datum encoding the number of vector components
  numComponents = numComponentsArg;
  /* allocate memory to store the supplied array components (assuming that
   * there are numComponents of them!) and initialize the components member 
   * datum using the memory address returned by new[]. 
   */
  components = new double[numComponents];
  /* initialize the ELEMENT VALUES of for the newly allocated array
   * using those supplied by the componentsArg argument.
   */
  for(unsigned int component = 0; component < numComponents; ++component){
    components[component] = componentsArg[component];
  }

  // NOTE: No return statement is neccessary.
}

/* ALMOST all C++ class methods, including constructors can 
 * be OVERLOADED in an identical fashion to ordinary functions.
 *
 * NOTE: An EXCEPTION is the class DESTRUCTOR. Only one destructor
 * may be defined for each class definition.
 *
 * By defining several overloaded constructor methods, classes can be 
 * initialized in different ways by SUPPLYING DIFFERENT PARAMETER
 * TYPES when calling the constructor method.
 * 
 * The Matrix class provides TWO constructors. The FIRST has NO
 * PARAMETERS and initializes the the object's member data using 
 * default values.
 *
 * The second has THREE parameters, specifying the values of the 
 * matrix elements the number of matrix dimensions and sizes of those
 * dimensions respectively.
 *
 * This example also introduces a NEW COMPACT SYNTAX FOR MEMBER DATA 
 * INITIALIZATION. IF a ":" token immediately follows the constructor's
 * parenthesized parameter list, then the constructor's body may be 
 * prefixed by a COMMA-SEPARATED LIST of initialization statements that 
 * use the CONSTRUCTOR STYLE or UNIFORM INITIALIZATION STYLE 
 * initialization syntax to initialize one or more member data.
 */
class Matrix {

  // The number of Matrix dimensions components 
  int dimensions;
  
  // Dynamically allocated array of Matrix elements 
  double * elements;
  
  /* Dynamically allocated array of comprising dimensions
   * elements, each of which specifies the size of the
   * corresponding dimension.
   */
  unsigned int * dimensionality;

public :

  /* DEFAULT CONSTRUCTOR accepts no parameters. The member data 
   * are initialized to default zero-equivalent values.
   *
   * NOTE: A compact member data initialization syntax has been used.
   */
  Matrix():
    dimensions(0), // initialize number of dimensions to 0.
    elements(nullptr), // initialize pointer-type member to nullptr
    dimensionality(nullptr) // initialize pointer-type member to nullptr
  {}

  /* PARAMETERIZED constuctor overload accepts three parameters
   * that map directly to the three data members dimensions, elements
   * and dimensionality. 
   * 
   * This is the DECLARATION. An OUT-OF-CLASS definition will be 
   * provided.
   */
  Matrix(int dimensionsArg,
	 double elementsArg[],
	 unsigned int dimensionalityArg[]
	 );
   
  /* DESTRUCTOR must free any memory that has been ALLOCATED using
   * new or new[].
   *
   * This is the DECLARATION. An OUT-OF-CLASS definition will be 
   * provided.
   */
  ~Matrix();

};

/* OUT-OF-CLASS DEFINITION of the three-parameter constructor for Matrix.
 */
Matrix::Matrix(int dimensionsArg,
	       double elementsArg[],
	       unsigned int dimensionalityArg[]
	       ):
  // ":" token indicates that member initialization statements follow
  dimensions(dimensionsArg) // only dimensions can be easily initialized
{
  // Remaining members require more complex initialization

  /* NOTE: The number of elements can be inferred from the dimensionality.
   * Declare and initialize a variable that will be used to compute the
   * number of elements. This will be the product of the dimension sizes.
   */ 
  unsigned int numElements(1); // initialize to 1. QUESTION: Why?
    
  // First, initialize dimensionality member data. Allocate memory and
  // copy values.
  dimensionality = new unsigned int[dimensions];
  for (unsigned int dimension = 0; dimension < dimensions; ++dimension){
    dimensionality[dimension] = dimensionalityArg[dimension];
    /* update computation of the number of elements using MULTIPLY-
     * ASSIGNMENT operator.
     */
    numElements *= dimensionality[dimension];
  }

  // Now initialize element member data
  elements = new double[numElements];
  for(int element = 0; element < numElements; ++element){
    elements[element] = elementsArg[element];
  }
}

/* OUT-OF-CLASS DEFINITION of the destructor for Matrix.
 * 
 * NOTE: The default constructor DOES NOT allocate any memory 
 * for data members and sets dimensionality and elements to "nullptr". 
 * Attempting to delete nullptr will generate an error  We need to 
 * check that elements and dimensionality are not equal to nullptr
 * BEFORE ATTEMPTING TO DELETE THEM.
 *
 * NOTE: This is a good example of why unallocated or deallocated
 * pointers should be set to nullptr. Accidentally using delete on
 * pointers that DO NOT ACTUALLY contain the addresses of allocated
 * memory could CORRUPT other data that is in use by your program.
 *
 * NOTE: The destructor DOES NOT return a value.
 * NOTE: The scope resolution operator "::" is still required. 
 */
Matrix::~Matrix(){
  // delete dimensionality if is not equal to nullptr.
  if(dimensionality != nullptr){
    delete[] dimensionality;
  }
  // delete elements if is not equal to nullptr.
  if(elements != nullptr){
    delete[] elements;
  }
}

/* CLASSES VERSUS OBJECTS:
 * =======================
 *
 * We have now covered all the syntax that is REQUIRED to declare and
 * define a CLASS in C++. Remember, the data members and methods that
 * are specified by a CLASS DEFINITION should really be considered as a 
 * DESCRIPTION of the BEHAVIOUR of C++ OBJECTS. 
 *
 * A C++ program creates objects that correspond to the descriptions 
 * provided by class definitions, then performs computations by inducing
 * INTERACTIONS between objects using the PUBLIC METHODS or DATA MEMBERS 
 * that are specified by the class definitions.
 */

#ifndef __CLING__
int main (){
#endif

  /* INSTANTIATING CLASSES:
   * ======================
   *
   * Creating an OBJECT that behaves according to a particular class 
   * definition is known as INSTANTIATING a class. The OBJECT that is 
   * created is called an INSTANCE of the class. A class is instantiated
   * by calling a CLASS CONSTRUCTOR and assigning the result to a 
   * variable with the appropriate type.
   *
   * RECALL that DEFINING a class also defines a new TYPE with the SAME
   * NAME as the class.
   *
   * C++ was designed to be an object oriented language, so the syntax
   * that is required to instantiate classes is very concise.
   *
   * For example, to declare and DEFAULT-INITIALIZE a variable of type 
   * Matrix (i.e. an instance of the Matrix class) the required code is
   * exactly analogous to the DECLARATION of a simple built-in type and 
   * consists only of (1) a type specifier and (2) an identifier i.e.   
   */
  // (1)          (2)
  Matrix defaultMatrixInstance; // The default constructor is used.

  /* To instantiate an object using a PARAMETERIZED (i.e. non-default)
   * constructor, append a parenthesized argument list after the 
   * identifier. This is analagous to the CONSTRUCTOR-STYLE initialization
   * syntax for built-in type variables. Te.g. 
   */

  // The desired number of dimensions for our Matrix instance
  unsigned int numDimensions(2); // CONSTRUCTOR-STYLE initialization

  // The sizes of each dimension in our Matrix instance 
  unsigned int dimensionSizes[2] = { 2, 2 }; // specify a 2x2 Matrix

  // The values for the elements of our matrix
  double matrixValues[4] = { 1, 2, 3, 4 };

  // Instantiate a Matrix object using the PARAMETERIZED constructor. 
  Matrix matrixInstance(numDimensions, matrixValues, dimensionSizes);

  /* It is also possible to declare pointers to class instances
   * using the "new" operator. In this case the syntax is a little more
   * complicated. The following statement (1) allocates memory for an 
   * instance of the Matrix class, calls the parameterized constructor (2)
   * which initializes the allocated memory (and actually allocates more
   * memory for its data members), returns the address of the FIRST BYTE 
   * of the memory representation of the Matrix instance and assigns (3)
   * this address to the pointer-to-Matrix (Matrix *) type (4) variable 
   * "pointerToMatrix" (5).
   */
  // (4)         (5)         (1)   (2)
  Matrix * pointerToMatrix = new Matrix(numDimensions,
					matrixValues,
					dimensionSizes);

  /* This syntax should seem familiar. Indeed it can be used to declare
   * and initialize pointers to built-in types using the CONSTRUCTOR-STYLE
   * initialization syntax e.g.
   */
  double * pointerToDouble = new double(2.0);

  /* ACCESSING PUBLIC DATA MEMBERS:
   * ==============================
   *
   * PUBLIC DATA MEMBERS of class instances can be ACCESSED using the 
   * MEMBER ACCESS "." operator. The basic syntax looks like:
   * 
   * INSTANCE_IDENTIFIER.MEMBER_DATUM_IDENTIFIER
   *
   * For a concrete example, RECALL the ContactDetailsHandler class definition 
   * included two public member data - "surname" and "otherNames"
   */
  // Instantiate a ContactDetails OBJECT.
  ContactDetailsHandler contact;

  // Access and SET the values of surname
  contact.surname = "GHOSTBUSTERS";

  // Check that the data really have been set.
  std::cout << "Who you gonna call? " << contact.surname << "!" << std::endl;

  /* CALLING PUBLIC METHODS:
   * =======================
   * The MEMBER ACCESS "." operator is also used to CALL PUBLIC METHODS of 
   * class instances. The basic syntax looks like:
   *
   * INSTANCE_IDENTIFIER.METHOD_IDENTIFIER(PARAMETER_LIST)
   *
   * NOTE: As with ordinary function calls, he parentheses are MANDATORY, 
   * even if the parameter list is empty.
   * 
   * Let's see a concrete example using the ContactDetailsHandler instance
   * we already created. 
   */

  // CALL the SETTER method to set the phone number.
  contact.setPhoneNumber(5552368);

  /* CALL the GETTER method to check it worked!
   * NOTE: The paretheses are MANDATORY even if the parameter list 
   * is empty.
   */
  std::cout << "Call now on "
	    << contact.getPhoneNumber() // METHOD CALL
	    << ". We're ready to believe you!" << std::endl;

  // Declare and initialize an array of strings to specify the lines
  // of the contact's address.
  std::string addressLines[4] = {"14 N. Moore Street",
				 "New York",
				 "New York",
				 "10013"};

  /* Call the PUBLIC setAddress METHOD using the MEMBER ACCESS "."
   * operator.
   */
  contact.setAddress(addressLines, 4);

  /* Check that setAddress worked by calling the PUBLIC getAddress 
   * method.
   */
  std::cout << contact.getAddress() << std::endl;

  /* SPECIAL HANDLING FOR POINTERS:
   * ==============================
   * To access the member data or call the methods of objects using 
   * POINTERS to object instances, you have TWO OPTIONS:
   *
   * 1) Use the DEREFERENCE OPERATOR "*" to access the value at the memory 
   * address held by the pointer and use the "." operator as before.
   * 2) Use the special MEMBER ACCESS OPERATOR FOR POINTERS "->" directly
   * with identifiers of pointer-type variables.
   *
   * To illustrate the use of "->", we COULD instantiate ANOTHER, DISTINCT
   * ContactDetailsHandler, and re-initialize all of the member data. 
   *
   * However, this is a good opportunity to introduce A NEW OPERATOR - 
   * the ADDRESS OF OPERATOR "&".
   *
   * The ADDRESS OF operator is used to obtain the MEMORY ADDRESS of a 
   * NON-POINTER type variable. To do this, PREPEND the identifier of
   * the NON-POINTER type variable with the "&" token. The returned address 
   * can then be assigned to a pointer-type variable e.g. 
   */

  ContactDetailsHandler * contactPointer = &contact;

  /* NOTE: contactPointer now contains the ADDRESS of the FIRST BYTE of
   * "contact". This is usually considered to be the ADDRESS OF THE
   * INSTANCE.
   */ 

  /* RESET the surname using OPTION 1 - DEREFERENCE and then ACCESS.
   * NOTE: the parentheses surrounding the dereference expression are
   * REQUIRED. QUESTION: Why? HINT: What are the prelevant operator
   * precedences?
   */
  (*contactPointer).surname = "Bond";

  /* SET the first element of the PUBLIC otherNames member datum
   * using OPTION 2 - The pointer-type-specific member access operator.
   */
  contactPointer->otherNames[0] = "James";

  /* RESET the phone number using OPTION 1.
   */
  (*contactPointer).setPhoneNumber(007); // This is actually legal C++! Why? 

  /* RESET the contact address lines using OPTION 2. Re-use our local variable
   * addressLines. Recall it has 4 elements - we will only need 3.
   */
  addressLines[0] = "Universal Exports";
  addressLines[1] = "London";
  addressLines[2] = "United Kingdom";
		    
  contactPointer->setAddress(addressLines, 3);

  // Print the results of our updates using OPTION 2.
  std::cout << "Name: " << contactPointer->surname << ", "
	    << contactPointer->otherNames[0] << " "
	    << contactPointer->surname << "\n"
	    << "Address: " << contactPointer->getAddress() << "\n"
	    << "Number: 00" << contactPointer->getPhoneNumber()
	    << std::endl;
  

#ifndef __CLING__
  return 0;
}
#endif
