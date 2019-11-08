# coding: utf-8
import sys

class SetConstant():
    class ConstError(TypeError):
        pass
    def __setattr__(self, name, value):
        if name in vars(self):
            raise self.ConstError("�萔��`���ꂽ�l�̍Ē�`�͏o���܂���B(%s)", "%name")
        self.__dict__[name] = value

sys.modules[__name__]=SetConstant()