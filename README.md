# -课上的项目，主要利用利用Qt中的Qpaint类实现棋盘界面设计

  期间利用二维数组来管理棋盘
  通过信号槽实现点击事件：
  通过检测落子的mousePressEvent函数来获取点击位置然后通过painter.drawEllipse来实现落子
  