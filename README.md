# Fuzzy-Control
這邊以瓦斯爐為例，輸入為爐子溫度，輸出為瓦斯用量。


模糊控制器的設計步驟

1.確定模糊控制器的結構

2.定義輸入、輸出模糊集合

3.定義輸入、輸出的歸屬函數

4.建立模糊控制規則

5.進行模糊推論

6.解模糊化

以此例來說明

1.使用一維模糊控制器
輸入為溫度、輸出為瓦斯量大小
![default](https://cloud.githubusercontent.com/assets/13445632/17082389/e4d027a4-51ae-11e6-857a-7116100a7ae2.png)

2.溫度T={溫暖、適中、冷}={PM、Z、NM}

  瓦斯Gas={大量、適中、少量}={PM、Z、NM}
  
3.定義歸屬函數

輸入歸屬函數
![default](https://cloud.githubusercontent.com/assets/13445632/17082426/8b5b22f8-51b0-11e6-8a57-034b07747cc6.png)

輸出歸屬函數

![default](https://cloud.githubusercontent.com/assets/13445632/17090081/662ac9b6-525f-11e6-9306-f4d71feac47a.png)

4.建立模糊規則

R1: if T is PM then Gas is NM

R2: if T is Z then Gas is Z

R3: if T is NM then Gas is PM

5.模糊推論

使用Mamdani的Max-min合成法


最後設定輸入溫度為 64 度來測試

![default](https://cloud.githubusercontent.com/assets/13445632/17082477/3d9fcddc-51b2-11e6-9d6f-f0aa0fd96096.png)

若溫度為 76 度來測試

![default](https://cloud.githubusercontent.com/assets/13445632/17082489/8f0a8de2-51b2-11e6-8bee-6ea160ba04c0.png)

若溫度為 68 度來測試


![default](https://cloud.githubusercontent.com/assets/13445632/17082495/d38bba90-51b2-11e6-9b58-79c7960faf42.png)




此範例參考此書"類神經網路控制理論入門與應用" 王進德 
