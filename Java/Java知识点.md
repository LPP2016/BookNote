## 基本类型
- char -- 2 bytes
- boolean -- 1 bit, 1 byte or 4 bytes
- byte -- 1 byte
- short -- 2 bytes
- int -- 4 bytes
- long -- 8 byte
- float -- 8 bytes
- double -- 8 bytes

## 基本类型和封装类型的区别
 - 传递方式：值传递 vs.  引用传递
 - final修饰，不能扩展类和方法 vs. 有方法和属性
 - 默认值：0 vs. null
 - 存储位置： 栈 vs. 地址存在栈内，对象本身存在堆内
 - 基本数据类型的好处：速度快（不涉及到对象的构造和回收）
 - 封装类：更好的处理数据之间的转换
## equals hashcode 和 == 的区别
- 基本数据类型采用==比较值
- 引用类型（类，接口，数组），==用于比较对象存放的地址（栈中的值），equals用于比较对象的内容
- 若a.euqals(b)，则a.hashCode()==b.hashCode()。反之不一定成立。在set的多次插入操作中，hashcode能提高效率。
- 覆盖equals时需要覆盖hashCode，否则所有基于hash的集合无法正常运作。

