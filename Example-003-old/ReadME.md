<A href="http://www.opengl.org"><IMG src='https://www.khronos.org/assets/images/api_logos/opengl.png' border=0 width="180" 
height="97"></A>

<H3>The <i>'Example-003 (Old Mode)'</i> Test</H3>

The <i>'Example-003 (Old Mode)'</i> Test draws the <i>'filled version'</i> of the quadrilateral (in <i>'red'</i>) with vertices <i>'(30,20,0)'</i> - <i>'(80,20,0)'</i> - <i>'(80,80,0)'</i> - <i>'(20,80,0)'</i> in an <A href="http://www.opengl.org"><i>OpenGL</i></A> window, and provides a basic interaction mechanism with the user. In fact, the user can apply (upon request) the following orthographic projections to the scene:<p><ol>
<li value="0">the orthographic viewing box <i>'[0,100]' x '[0,100]' x '[-1,1]'</i> is activated by pressing the <i>'0'</i> key (the <i>'viewing configuration #0'</i>). This is the standard orthographic viewing box of the scene, and the quadrilateral is completely rendered in the middle of the scene.<p></li>
<li value="1">The orthographic viewing box <i>'[-100,100]' x '[-100,100]' x '[-1,1]'</i> is activated by pressing the <i>'1'</i> key (the <i>'viewing configuration #1'</i>). The reduced and scaled quadrilateral is completely rendered in the top right corner of the scene.<p></li>
<li value="2">The orthographic viewing box <i>'[20,80]' x '[20,80]' x '[-1,1]'</i> is activated by pressing the <i>'2'</i> key (the <i>'viewing configuration #2'</i>). This orthographic viewing box does not cover entirely the ortographic projection of the quadrilateral, which is partially rendered in the middle of the scene.<p></li>
<li value="3">The orthographic viewing box <i>'[0,100]' x '[0,100]' x '[-2,5]'</i> is activated by pressing the <i>'3'</i> key (the <i>'viewing configuration #3'</i>). The quadrilateral is completely rendered in the middle of the scene as like as when the standard orthographic viewing box is exploited, even if this ortographic viewing box is different.<p></li>
<li value="4">The orthographic viewing box <i>'[0,200]' x '[0,200]' x '[-1,1]'</i> is activated by pressing the <i>'4'</i> key (the <i>'viewing configuration #4'</i>). The reduced and scaled quadrilateral is completely rendered in the bottom left corner of the scene.<p></li>
<li value="5">The orthographic viewing box <i>'[120,200]' x '[90,200]' x '[-1,3]'</i> is activated by pressing the <i>'5'</i> key (the <i>'viewing configuration #5'</i>). This orthographic viewing box does not intersect the orthographic projection of the quadrilateral, which is not rendered at all.<p></li></ol><p>Likewise, the window of interest can be closed by pressing any among the <i>'Q'</i>, the <i>'q'</i>, and the <i>'Esc'</i> keys.<p><table border=0 width=100%><tr>
<td><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example003_old_conf0.png' border='1' width='456' height='470'></td>
<td><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example003_old_conf1.png' border='1' width='456' height='470'></td></tr>
<tr><td>The <i>'viewing configuration #0'</i> (press the <i>'0'</i> key).</td><td>The <i>'viewing configuration #1'</i> (press the <i>'1'</i> key).</td></tr>
<tr>
<td><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example003_old_conf2.png' border='1' width='456' height='470'></td>
<td><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example003_old_conf3.png' border='1' width='456' height='470'></td></tr>
<tr><td>The <i>'viewing configuration #2'</i> (press the <i>'2'</i> key).</td><td>The <i>'viewing configuration #3'</i> (press the <i>'3'</i> key).</td></tr>
<tr>
<td><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example003_old_conf4.png' border='1' width='456' height='470'></td>
<td><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example003_old_conf5.png' border='1' width='456' height='470'></td></tr>
<tr><td>The <i>'viewing configuration #4'</i> (press the <i>'4'</i> key).</td><td>The <i>'viewing configuration #5'</i> (press the <i>'5'</i> key).</td></tr></table><hr><p>

<h4>Dependencies</h4>

The <i>'Example-003 (Old Mode)'</i> Test is based on the so-called <i>OpenGL old (direct drawing) mode</i>, and requires the following dependencies:<ul>

<li>the <A href="http://www.opengl.org"><i>OpenGL</i></A> package, distributed with the platform of interest (see the <i><A href="https://www.khronos.org/opengl/wiki/Getting_Started">Official Documentation</A></i>);</li>
<li>the <i><A href="https://www.opengl.org/resources/libraries/glut/">OpenGL Utility Toolkit (GLUT)</A></i> package (or the <A href="http://freeglut.sourceforge.net/"><i>FreeGLUT</i></A> package);</li>
<li>the <A href="http://glew.sourceforge.net/"><i>OpenGL Extension Wrangler Library (GLEW)</i></A> package.</li></ul><p>In particular, this test consists of the <i>'Example-003-old'</i> executable file (in the <i>'bin'</i> folder), starting uniquely from the <i>'main.cpp'</i> C++ source file (in the <i>'src'</i> folder).<p>Several methods for building this test are provided.<p><table border=1><tr><td><p><b>ATTENTION:</b><p>The majority of the dependencies for this test are stable, but are currently deprecated, and several warning messages may appear during the building process.<p></td></tr></table><p><hr><p>

<h4>Instructions for building this test with the <i><A href="http://cmake.org">CMake Building Tool</A></i></h4>

This test is built by using the <i>classic</i> instructions for building a program with the <i><A href="http://cmake.org">CMake Building Tool</A></i> from the <i>'cmake'</i> folder:
<pre>mkdir build
cd build
cmake ..
make
</pre><p>As mentioned above, the <i>'Example-003-old'</i> executable file is created in the <i>'bin'</i> folder. For instance, this test is executed by running:<pre>./bin/Example-003-old</pre><p>This building method is tested with the <A href="http://gcc.gnu.org/"><i>GCC</i></A> under the Ubuntu Linux 16.0.4 (LTS), as well as with the <A href="http://clang.llvm.org/"><i>CLANG</i></A> compiler under the MacOsX 11.* El-Capitan (and higher), and the <A href="http://www.visualstudio.com/"><i>Microsoft Visual Studio (Community Edition 2015)</i></A> under the Microsoft Windows 10.<p>In this latter case, three custom projects are automatically generated, and ready to be open in the <A href="http://www.visualstudio.com/"><i>Microsoft Visual Studio (Community Edition 2015)</i></A>. The solution file of interest is the <i>'Example-003-old.sln'</i> solution file, which can be open and built in the program without being modified.<p>

All dependencies of the <i>'Example-003 (Old Mode)'</i> Test are supported automatically by the <i><A href="http://cmake.org">CMake Building Tool</A></i> through a built-in manifest file. In particular, they are often pre-installed in a generic GNU/Linux distribution, and distributed in conjunction with the <A href="http://developer.apple.com/xcode/"><i>Apple XCode</i></A>. Thus, they should be found by the script of interest without problems in these platforms.<p>Instead, these libraries are not standard in the Microsoft Windows, and must be installed properly. For the sake of simplicity, the Win32 versions for the auxiliary libraries of interest in the <i>'../../depends'</i> folder are exploited, if the <i><A href="http://cmake.org">CMake Building Tool</A></i> fails while performing their automatic identification. This means that the resulting solution file creates automatically the <i>'Example-003-old.exe'</i> Win32 executable file.<p><hr><p>

<h4>Instructions for building this test with the <i><A href="http://www.visualstudio.com/">Microsoft Visual Studio (Community Edition 2015)</A></i></h4>

This test is also built by using the <A href="http://www.visualstudio.com/"><i>Microsoft Visual Studio (Community Edition 2015)</i></A>. In particular, the <i>'vstudio'</i> folder contains the <i>'Example-003-old.sln'</i> solution file, which can be open and built in the program without being modified. It can be built by simply clicking on the <i>'Build'</i> command.

Note that this solution file is independently created from scratch, and is different from the solution file, which may be generated automatically by the <i><A href="http://cmake.org">CMake Building Tool</A></i>.

Specifically, the Win32 versions for the auxiliary libraries of interest in the <i>'../../depends'</i> folder are exploited for building the  <i>'Example-003 (Old Mode)'</i> Test. This implies that the <i>'Example-003-old.sln'</i> solution file is set up for including these auxiliary libraries, and it should not be modified, unless you are an expert. Furthermore, it is mandatory to enable the building for a generic Win32 platform for creating correctly the <i>'Example-003-old.exe'</i> Win32 executable file.<p>An interested user finds more details in the Official Documentation of the <i><A href="http://www.visualstudio.com/">Microsoft Visual Studio (Community Edition 2015)</A></i>.<p><hr><p>

<h4>Instructions for building this test with the <i><A href="http://developer.apple.com/xcode/">Apple XCode</A></i></h4>

This test is also built by using the <A href="http://developer.apple.com/xcode/"><i>Apple XCode</i></A> (based on the <A href="http://clang.llvm.org/"><i>CLANG</i> compiler</A>) under the MacOsX 11.* El-Capitan (and higher). In particular, the <i>'xcode'</i> folder contains the <i>'Example-003-old.xcodeproj'</i> project file, which can be open and built in the program without being modified. It can be built by simply clicking on the <i>'Build & Run'</i> command.

Note that this project file is independently created from scratch, and is different from the project file, which may be generated automatically by the <i><A href="http://cmake.org">CMake Building Tool</A></i>.<p>

Specifically, this project file includes the versions (frameworks) of the <A href="http://www.opengl.org"><i>OpenGL</i></A> and of the <i><A href="https://www.opengl.org/resources/libraries/glut/">OpenGL Utility Toolkit (GLUT)</A></i> packages, that are distributed in conjunction with the <A href="http://developer.apple.com/xcode/"><i>Apple XCode</i></A>. Instead, the headers and the library files of the <A href="http://glew.sourceforge.net/"><i>OpenGL Extension Wrangler Library (GLEW)</i></A> are assumed to be stored in the <i>'/usr/local/include'</i> and the <i>'/usr/local/lib'</i> folders, respectively. This implies that the <i>'Example-003-old.xcodeproj'</i> project file is set up for including these auxiliary libraries, and it should not be modified, unless you are an expert.<p>An interested user finds more details in the Official Documentation of the <A href="http://developer.apple.com/xcode/"><i>Apple XCode</i></A>.<p><hr><p><table border=1><tr><td><p><b>ATTENTION:</b><p>This test is not related officially to the <i><A href="https://www.khronos.org/">Khronos Group</A></i>. All trademarks or registered trademarks are the property of their respective owners.</td></tr></table>


