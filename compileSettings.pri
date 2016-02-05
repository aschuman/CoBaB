CONFIG += warn_on

travis{
    QMAKE_CXXFLAGS += -std=c++14
}else{
    CONFIG += c++14
}
