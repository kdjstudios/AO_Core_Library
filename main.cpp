#include <iostream>
#include <string.h>
#include "ao.h"


using namespace std;
using namespace ::ao;
using namespace ::ao::core;
//Testing Case Data
#define TEST_INSERT1_SIZE 17
string test_insert1[]=
{
    "hh","dd","ll","bb","ff","jj","nn","aa","cc","ee","gg","ii","kk","mm","oo",
//expect to fail
    "hh","cc"
};
//sequential ascending order
#define TEST_INSERT3_SIZE 17
string test_insert3[]=
{
    "hh","gg","ff","ee","dd","cc","bb","aa","ii","jj","kk","ll","mm","nn","oo",
//expect to fail
    "**","aa"
};
// sequential, sorted ascending
#define TEST_INSERT4_SIZE 18
string test_insert4[]=
{
    "aa","bb","cc","dd","ee","ff","gg","hh","ii","jj","kk","ll","mm","nn","oo",
//expect to fail
    "aa","##","oo"
};
// sequential, sorted descending
#define TEST_INSERT5_SIZE 18
string test_insert5[]=
{
    "oo","nn","mm","ll","kk","jj","ii","hh","gg","ff","ee","dd","cc","bb","aa",
//expect to fail
    "aa","hh","__"
};
#define TEST_SEARCH1_SIZE 17
string test_search1[]=
{
    "aa","bb","cc","dd","ee","ff","gg","hh","ii","jj","kk","ll","mm","nn","oo",
//expect to fail
    "@@","pp"
};
#define TEST_REMOVE1_SIZE 18
string test_remove1[]=
{
    "aa","bb","cc","dd","ee","ff","gg",
    "hh","ii","jj","kk","ll","mm","nn","oo",
//expect to fail
    "oo","@@","pp"
};

void print(RetStat test)
{
    if(test==SUCCESS)
    {
        cout << "Test was a Success!" << endl;
    }
    else
    {
        cout << "Test was a Fail!" << endl;
    }
    cout << "Press any key to quit. ";
    char blah = ' ';
    cin.get(blah);
}
//
RetStat quaternionTEST()
{
// Demonstrates other copy constructor, static member variable usage, and unary operator-
//const Vector3 backward(-Vector3::Forward);
    const Quaternion backward(Quaternion::One*3);
// Demonstrates cross product
    const Quaternion right(normalize(backward));

// Demonstrates constructor
    Quaternion testVect(10.0f, 30.0f,10.0f,22.0f);

// Demonstrates operator<<
    cout << testVect << '\n';
// Demonstrates clamp/truncate method
//truncate(testVect,3);
    cout << "truncated at 3: " << testVect << '\n';

// Demonstrates reflect method
//const Quaternion reflection( reflect(testVect,backward) );
//cout << "Reflected off surface with 'backward' as the normal, " << reflection << '\n';

// Demonstrates operator*, we don't const 'doubleFwd' because we want to use normalize later.
    Quaternion doubleFwd(Quaternion::One* 2);

    cout << "Double Forward, " << doubleFwd << '\n';
    cout << "Double Forward Length: " << magnitude(doubleFwd) << '\n';
    toNormalized(doubleFwd);
    cout << "Normalized Double Forward, now what is the length?: " << magnitude(doubleFwd) << '\n';
//zero(doubleFwd);
    cout << "Zero out Double Forward, now what is the length?: " << doubleFwd << '\n';
//My compiler confuses 'distance' with an c iterator
//cout << "Distance from Double Forward to Reflection: " << (float)AO::Quaternion::dist(doubleFwd,reflection) << '\n';
//Quaternion per( perp(backward) );
//cout << "Perpendicular to 'backward':" << per << '\n';
//cout << "Sign of Perpendicular and double(Not Working) " << sign(per,doubleFwd) << '\n';

    return SUCCESS;
}
//
RetStat vector3TEST()
{
// Demonstrates other copy constructor, static member variable usage, and unary operator-
//const vector3 backward(-vector3::Forward);
    const vector3 backward(vector3::Backward);
// Demonstrates cross product
    const vector3 right( cross(vector3::Forward,vector3::Up ));

// Demonstrates constructor
    vector3 testVect(10.0f, 30.0f, 1.0f);

// Demonstrates operator<<
    cout << testVect << '\n';
// Demonstrates clamp/truncate method
    truncate(testVect,3);
    cout << "truncated at 3: " << testVect << '\n';

// Demonstrates reflect method
    const vector3 reflection( reflect(testVect,backward) );
    cout << "Reflected off surface with 'backward' as the normal, " << reflection << '\n';

// Demonstrates operator*, we don't const 'doubleFwd' because we want to use normalize later.
    vector3 doubleFwd(vector3::Forward* 2);

    cout << "Double Forward, " << doubleFwd << '\n';
    cout << "Double Forward Length: " << magnitude(doubleFwd) << '\n';
    toNormalized(doubleFwd);
    cout << "Normalized Double Forward, now what is the length?: " << magnitude(doubleFwd) << '\n';
    toZero(doubleFwd);
    cout << "Zero out Double Forward, now what is the length?: " << doubleFwd << '\n';
//My compiler confuses 'distance' with an c iterator
    cout << "Distance from Double Forward to Reflection: " << (float)dist(doubleFwd,reflection) << '\n';
    vector3 perp3( perpendicular(backward) );
    cout << "Perpendicular to 'backward':" << perp3 << '\n';
    cout << "Sign of Perpendicular and double(Not Working) " << sign(perp3,doubleFwd) << '\n';

    return SUCCESS;
}
//
RetStat vector4TEST()
{
// Demonstrates other copy constructor, static member variable usage, and unary operator-
//const vector3 backward(-vector3::Forward);
    const vector4 backward=vector4(0.0f,0.0f,-1.0f,1.0f);
// Demonstrates cross product
    const vector4 right;

// Demonstrates constructor
    vector4 testVect(10.0f, 30.0f, 1.0f,22.0f);

// Demonstrates operator<<
    cout << testVect << '\n';
// Demonstrates clamp/truncate method
//truncate(testVect,3);
//cout << "truncated at 3: " << testVect << '\n';

// Demonstrates reflect method
//const vector4 reflection( reflect(testVect,backward) );
//cout << "Reflected off surface with 'backward' as the normal, " << reflection << '\n';

// Demonstrates operator*, we don't const 'doubleFwd' because we want to use normalize later.
    vector4 doubleFwd=backward*-2;

    cout << "Double Forward, " << doubleFwd << '\n';
    cout << "Double Forward Length: " << magnitude(doubleFwd) << '\n';
    doubleFwd=normalize(doubleFwd);
    cout << "Normalized Double Forward, now what is the length?: " << magnitude(doubleFwd) << '\n';
//toZero(doubleFwd);
//cout << "Zero out Double Forward, now what is the length?: " << doubleFwd << '\n';
//My compiler confuses 'distance' with an c iterator
//cout << "Distance from Double Forward to backward: " << (float)dist(doubleFwd,backward) << '\n';
//vector4 perp3( perpendicular(backward) );
//cout << "Perpendicular to 'backward':" << perp3 << '\n';
//cout << "Sign of Perpendicular and double(Not Working) " << sign(perp3,doubleFwd) << '\n';

    return SUCCESS;
}
//
RetStat vector2TEST()
{
// Demonstrates other copy constructor, static member variable usage, and unary operator-
//const vector3 backward(-vector3::Forward);
    const vector2 backward(vector2::Zero);
// Demonstrates cross product
    const vector2 right( crossVec(vector2::Zero,vector2::One));

// Demonstrates constructor
    vector2 testVect(10.0f, 30.0f);

// Demonstrates operator<<
    cout << testVect << '\n';
// Demonstrates clamp/truncate method
    truncate(testVect,3);
    cout << "truncated at 3: " << testVect << '\n';

// Demonstrates reflect method
    const vector2 reflection( reflect(testVect,backward) );
    cout << "Reflected off surface with 'backward' as the normal, " << reflection << '\n';

// Demonstrates operator*, we don't const 'doubleFwd' because we want to use normalize later.
    vector2 doubleFwd(vector2::One* 2);

    cout << "Double Forward, " << doubleFwd << '\n';
    cout << "Double Forward Length: " << magnitude(doubleFwd) << '\n';
    normalize(doubleFwd);
    cout << "Normalized Double Forward, now what is the length?: " << magnitude(doubleFwd) << '\n';
    zero(doubleFwd);
    cout << "Zero out Double Forward, now what is the length?: " << doubleFwd << '\n';
//My compiler confuses 'distance' with an c iterator
    cout << "Distance from Double Forward to Reflection: " << (float)dist(doubleFwd,reflection) << '\n';
    vector2 per( perpendicular(backward) );
    cout << "Perpendicular to 'backward':" << per << '\n';
    cout << "Sign of Perpendicular and double(Not Working) " << sign(per,doubleFwd) << '\n';

    return SUCCESS;
}
//
/*
RetStat EntityTEST()
{
    //EntityManager* iManager =EntityManager::Instance();
    BaseEntity tempr;

    //iManager->RegisterEntity(tempr);
    return SUCCESS;
}
//*/
/*
RetStat MovingEntityTEST()
{
    //EntityManager* iManager =EntityManager::Instance();
    MovingEntity tempr;

    //iManager->RegisterEntity(tempr);
    return SUCCESS;
}
//*/
/*
RetStat BodyEntityTEST()
{
    //EntityManager* iManager =EntityManager::Instance();
    BodyEntity tempr;
    tempr.SetDragCoefficient(1);
    tempr.SetThrust(10);
    tempr.SetVelocity(30);
    for(int index=0; index<30; index++)
    {
        tempr.StepSimulation((float)index);
        cout << tempr.Velocity();
    }
    //iManager->RegisterEntity(tempr);
    return SUCCESS;
}
*/
/*
RetStat EntityManagerTEST(){
  //EntityManager* iManager =EntityManager::Instance();
    BodyEntity tempr;
    tempr.SetDragCoefficient(1);
    tempr.SetThrust(10);
    tempr.SetVelocity(30);
    for(int index=0; index<30;index++){
        tempr.StepSimulation((float)index);
        cout << tempr.Velocity();
    }
    //iManager->RegisterEntity(tempr);
    return SUCCESS;
}
//*/

RetStat FSMTEST()
{


    //create a miner
    //Miner Bob(ent_Miner_Bob);

    //create his wife
    //MinersWife Elsa(ent_Elsa);

    //run Bob and Elsa through a few Update calls
    for (int i=0; i<20; ++i)
    {
        //Bob.Update();
        //Elsa.Update();

    }

    return SUCCESS;
}
//
RetStat matrix2x2TEST()
{
    float theta=30.0f;
    matrix2x2 start;
    matrix2x2 rot = rotation2d(theta);
    start=matrix2x2(1.0f,2.0f,3.0f,4.0f);
    cout << "Start matrix: " <<start;
    cout << "Rotation matrix of: " <<theta<<"; "<< rot <<endl;
    cout << "Start*Rotation: " << start*rot<<endl;
    cout << "Start+Rotation: " << start+rot<<endl;
    //cout << "Start/Rotation: " << start/rot<<endl;
    cout << "Start-Rotation: " << start-rot<<endl;
    vector2 temp=vector2(2.0f,3.0f);
    cout << "Vector2 temp: " <<temp<<endl;
    cout << "start*temp: " << start*temp<<endl;
    return SUCCESS;
}
RetStat matrix3x3TEST()
{
    float theta=30.0f;
    matrix3x3 start;
    matrix3x3 rot = matrix3x3();
    start=matrix3x3(1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f);
    cout << "Start matrix: " <<start;
    cout << "Rotation matrix of: " <<theta<<"; "<< rot <<endl;
    cout << "Start*Rotation: " << start*rot<<endl;
    cout << "Start+Rotation: " << start+rot<<endl;
    //cout << "Start/Rotation: " << start/rot<<endl;
    cout << "Start-Rotation: " << start-rot<<endl;
    //vector2 temp=vector2(2.0f,3.0f);
    //cout << "Vector2 temp: " <<temp<<endl;
    //cout << "start*temp: " << start*temp<<endl;
    return SUCCESS;
}
RetStat matrix4x4TEST()
{
	cout << "Starting Test";
    float theta=30.0f;
    matrix4x4 start;
    matrix4x4 rot = rotateYXZ(40.0f,20.0f,10.0f);
    start=matrix4x4(1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f,10.0f,11.0f,12.0f,13.0f,14.0f,15.0f,16.0f);
    cout << "Start matrix: " <<start;
    cout << "Rotation matrix of: " <<theta<<"; "<< rot <<endl;
    cout << "Start*Rotation: " << start*rot<<endl;
    cout << "Start+Rotation: " << start+rot<<endl;
    //cout << "Start/Rotation: " << start/rot<<endl;
    cout << "Start-Rotation: " << start-rot<<endl;
    matrix4x4 lk=look(vector3::Zero,vector3::Forward,vector3::Up);
    matrix4x4 per=perspective(80.0f,1.0f,1.0f,30.0f);
    matrix4x4 back=translate(vector3::Backward);
    vector3 vtemp=transform(vector3::Backward,back);
    matrix4x4 scal=scale(vector3::Left);
    cout << "LOOK matrix: " <<lk<<endl;
    cout << "PER matrix: " <<per <<endl;
    cout << "look scaled:"<<lk*scal;
    vector4 temp=vector4(2.0f,3.0f,1.0f,3.0f);
    cout << "Vector4 temp: " <<temp<<endl;
    cout << "start*temp: " << temp*start<<endl;
    return SUCCESS;
}
/*/
RetStat SortsTEST(){
    return SUCCESS;
}
}}}
//
RetStat ClockTEST(){
    return SUCCESS;
}
//
RetStat ListsTEST(){
    return SUCCESS;
}
//
RetStat StrTEST(){
    return SUCCESS;
}
//
RetStat LineTEST(){
    return SUCCESS;
}
//
RetStat MeshTEST(){
    return SUCCESS;
}
//
RetStat ShapeTEST(){
    return SUCCESS;
}
//
RetStat StackTEST(){
    return SUCCESS;
}
//
RetStat VectorTEST(){
    return SUCCESS;
}
//
RetStat aoBSTTEST(){
	string searchKey;
	RetStat overallTest=SUCCESS,test=SUCCESS;
	BinarySearchTree<string> * bt=new BinarySearchTree<string>();
	cout << endl << endl << "TEST #1 (by layers)" << endl;
	cout << endl;
	for(int ii=0;ii<TEST_INSERT1_SIZE;ii++) {
		searchKey=test_insert1[ii];
		if(bt->insert(searchKey)==FAIL){
			test=FAIL;
			overallTest=FAIL;
		}
	}
	cout << endl;
	for(int ii=0;ii<TEST_SEARCH1_SIZE;ii++) {
		searchKey=test_search1[ii];
		if(bt->search(searchKey)==FAIL){
			test=FAIL;
			overallTest=FAIL;
		}
	}
	print(test);
	cout << endl;
	test=SUCCESS;
	cout << endl << endl << "TEST #3 (descending & ascending sequences)"
	<< endl;
	cout << endl;
	for(int ii=0;ii<TEST_INSERT3_SIZE;ii++) {
		searchKey=test_insert3[ii];
		if(bt->insert(searchKey)==FAIL){
			test=FAIL;
			overallTest=FAIL;
		}
	}

	cout << endl;
	bt->clear();
	print(test);
	test=SUCCESS;
	cout << endl << endl << "TEST #4 (ascending sequence)" << endl;
	cout << endl;
	for(int ii=0;ii<TEST_INSERT4_SIZE;ii++) {
		searchKey=test_insert4[ii];
		if(bt->insert(searchKey)==NULL){
			test=FAIL;
			overallTest=FAIL;
		}
	}

	cout << endl;
	bt->clear();
	print(test);
	test=SUCCESS;
	cout << endl << endl << "TEST #5 (descending sequence)" << endl;
	cout << endl;
	for(int ii=0;ii<TEST_INSERT5_SIZE;ii++) {
		searchKey=test_insert5[ii];
		if(bt->insert(searchKey)==FAIL){
			test=FAIL;
			overallTest=FAIL;
		}
	}

	cout << endl;
	bt->clear();
	print(test);
	cout << endl << endl;
	delete bt;

	return overallTest;
}
//*/

int main()
{
    print(vector2TEST());
    print(vector3TEST());
    print(vector4TEST());
    print(quaternionTEST());
    //print(aoBSTTEST());
    print(matrix2x2TEST());
    print(matrix3x3TEST());
    print(matrix4x4TEST());
    print(FSMTEST());


    DoublyLinkedList::exercise();
    //SinglyLinkedList::exercise();

    cout << "Press any key to quit. ";
    char blah = ' ';
    cin.get(blah);
    return 0;
}
